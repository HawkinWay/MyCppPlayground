# Smart Pointers

*#include <memory>*

- unique_ptr
- shared_ptr
- weak_ptr

---

|Dimension|unique_ptr|shared_ptr|weak_ptr|auto_ptr|
|--|--|--|--|--|
|Semantics|exclusive ownership|share ownership, strong reference count|observer, has no objects|Ownership is transferred directly during copying, and the source object is set to null.
|Structure|T* ptr|T* ptr + ControlBlock* cb|T* ptr + ControlBlock* cb|
|Control block|-|strong reference count, weak reference count|only operates weak reference count|
|Reference count|-|strong reference count manages object's lifecycle; weak reference count manages control block's lifecycle; **atomic operation**|only add weak count, has no impact on object's lifecycle|
|Copyable|No|Yes|Yes|
|Movable|Yes|Yes|Yes|
|Size|ususally equals to 1 pointer|usually equals to 2 pointer(16B in 64bit)|usually equals to 2 pointer|
|Destruct|call deleter|strong count = 0, destroy object; weak count = 0, release control block|weak count = 0 && strong count = 0, release control block|
|Dereference|*, ->, []|*, ->, []|->|
|Empty state|after moving; `reset`/`release`|after moving; `reset`|**default** empty|
|Overhead|lowest, close to raw pointer|atomic count, control block allocation, inderect access|control block operation, lock() atomicity overhead|
|Argument design|pass-by-value, use `std::move()` in function|pass `const shared_ptr<T>&` if only need to use it, because pass-by-value will add reference count|-|
|Remarks|-|Only reference count is **thread safe**, bacause it's atomic. |-|Created in C++98, deprecated in C++11, removed in C++17|

```cpp
shared_ptr<int> sp = std::make_shared<int>(3);
weak_ptr<int> wp = sp;

shared_ptr<int> sp_of_wp = wp.lock();
if(sp_of_wp != nullptr){
    // use sp_of_wp do something...
}
```

### A circular reference issue

```cpp
struct A{
    shared_ptr<B> b;
    int m;
};

struct B{
    shared_ptr<A> a;
    int m;
};

int main(){
    auto a = std::make_shared<A>(); // A:1
    auto b = std::make_shared<B>(); // A:1, B:1

    a->b = b;   // A:1, B:2
    b->A = a;   // A:2, B:2

    return 0;
}

// When exiting the scope, A:1, B:1. The strong reference counts are not 0, so the two pointers won't release correctly.

```

How to fix? Use weak_ptr;

```cpp
struct A{
    shared_ptr<B> b;
    int m;
};

struct B{
    weak_ptr<A> a;
    int m;
};

int main(){
    auto a = std::make_shared<A>(); // A:1
    auto b = std::make_shared<B>(); // A:1, B:1

    a->b = b;   // A:1, B:2
    b->A = a;   // A:1, B:2

    return 0;
}

// When exiting the scope, A:0, B:1. So A released, it's member shared_ptr<B> released too. B:0, then B released.
```


### `shared_ptr` thread safety

When multithreads operate multishared_ptrs copies, they sharing a same control block. So the copy/destruction is safe, beacause strong reference count is atomic.

When multithreads operate a same `shared_ptr` object, this is not safe because we need. We need add mutex.

When multithreads access a same managed object, whether it is safe depends on the object itself.

So:
- ✅ Control block's reference count is thread safe.
- ❌ shared_ptr object is not thread safe.
- ❌ The managed object is not thread safe.

---

## Some methods

### .get()

returns a pointer to the managed object

### .release() *unique_ptr*

returns a pointer to the managed object and releases the ownership

### .reset()

replaces the managed object

### .swap()

swaps the managed objects

### .lock() *weak_ptr*

creates a `shared_ptr` that manages the referenced object

### `enable_shared_from_this<T>`

> *Extend lifecycle, always be used in asynchronous callback*

enables an object already be managed by a `shared_ptr` to safely obtain a `shared_ptr` pointing to iteself.

calling `shared_from_this()` in the constructor will throw a `bad_weak_ptr` because `shared_ptr` has not yet taken over the object, and the weak pointer hasn't been initialized.

A double delete case, like Benefits#4 below:
```cpp
class Widget{
    std::shared_ptr<Widget> getSelf(){
        return std::shared_ptr<Widget>(this);   // *this* is raw pointer, use this to construct shared_ptr will get a independent shared_ptr with new control block
    }
}

auto a = std::make_shared<Widget>();
auto b = a->getSelf();  // error, a, b sharing the same one object but having their own control block. This will lead double free
```

```cpp
class Widget : public enable_shared_from_this<Widget>{
    std::shared_ptr<Widget> getSelf(){
        return shared_from_this();
    }
}

auto a = std::make_shared<Widget>();
auto b = a->getSelf();  // a, b sharing the same one control block
```

### make_unique<>() and make_shared<>()

creates a unique/shared pointer to the managed object

> **Benefits:**

#### 1. Prevent raw pointer leak (*exception safe*)

```cpp
void f(std::shared_ptr<Widget> sp, int x);

int g();

f(std::shared_ptr<Widget>(new Widget), g());
```

Before C++17, the order of evaluation of function arguments is unspecified.

In f() arguments list, the execute order may not "new -> shared_ptr construct -> g()", may be "new -> g() -> shared_ptr construct". In this case g() may throw exception, then shared_ptr can't release the raw pointer because it didn't construct. So there has potential memory leak.

Use `f(std::make_shared<Widget>(), g())` can prevent this situation. Because `make_shared` completes internal allocation and construction, then return a shared_ptr which already holds ownership directly.

#### 2. Avoid raw pointer exposure (*specific ownership*)

RAII, prevent forgetting `delete` or exception caused memory leak when use raw pointer.

#### 3. One allocation

> `make_unique` has no control block，so it's efficiency is almost as same as `unique_ptr<T>(new T)`. `make_unique`'s benifits are exception safe and clean.

`make_shared` is one allocation while `new` is two allocations.  

`shared_ptr` needs two part: the managed object and control block(reference count, deleter etc.). If we use `new`, there'are two allocations: new an object and shared_ptr's control block. But `make_shared` usually put an object and control block in the same continuous memory block, only allocate once. **This make construction faster, and cache-friendly**.

**Double edge:** If the object's size is very large, and meanwhile, there's a `weak_ptr` reference this object(means the control block is still living). Although the strong reference count is 0, the memory block which the object using can't release until all `weak_ptr` destroyed. This is `Delayed reclamation`.

#### 4. Avoid duplicate control blocks

```cpp
Widget* raw = new Widget;

std::shared_ptr<Widget> a(raw);
std::shared_ptr<Widget> b(raw);     // error, two independent control blocks, will cause double free
```



```cpp
auto a = std::make_shared<Widget>();
auto b = a;     // sharing the same one control block
```



