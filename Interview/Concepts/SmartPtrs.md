# Smart Pointers

*#include <memory>*

- unique_ptr
- shared_ptr
- weak_ptr

---

|Dimension|unique_ptr|shared_ptr|weak_ptr|
|--|--|--|--|
|Semantics|exclusive ownership|share ownership, strong reference count|observer, has no objects|
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


```cpp
shared_ptr<int> sp = std::make_shared<int>(3);
weak_ptr<int> wp = sp;

shared_ptr<int> sp_of_wp = wp.lock();
if(sp_of_wp != nullptr){
    // use sp_of_wp do something...
}
```

## A circular reference issue

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

### make_unique<>() and make_shared<>()

creates a unique/shared pointer to the managed object

### .lock() *weak_ptr*

creates a `shared_ptr` that manages the referenced object

**Benefits:**

1. Prevent raw pointer leak (*exception safe*)

```cpp
void f(std::shared_ptr<Widget> sp, int x);

int g();

f(std::shared_ptr<Widget>(new Widget), g());
```

Before C++17, the order of evaluation of function arguments is unspecified.

In f() arguments list, the execute order may not "new -> shared_ptr construct -> g()", may be "new -> g() -> shared_ptr construct". In this case g() may throw exception, then shared_ptr can't release the raw pointer because it didn't construct. So there has potential memory leak.

Use `f(std::make_shared<Widget>(), g())` can prevent this situation. Because `make_shared` completes internal allocation and construction, then return a shared_ptr which already holds ownership directly.

2. Avoid raw pointer exposure (*specific ownership*)

RAII, prevent forgetting `delete` or exception caused memory leak when use raw pointer.

3. Avoid duplicate control blocks

```cpp
Widget* raw = new Widget;

std::shared_ptr<Widget> a(raw);
std::shared_ptr<Widget> b(raw);     // error, two independent control blocks, will cause double free
```



```cpp
auto a = std::make_shared<Widget>();
auto b = a;     // sharing the same one control block
```



