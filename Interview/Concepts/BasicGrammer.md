# Basic Grammer

- inline
- static
- const
- constexpr
- noexcept

---

## inline

go [CppNotes/inline.cpp](../../CppNotes/inline.cpp)

---

## const

[CppNotes/const.cpp](../../CppNotes/const.cpp)

### Top-level const: the object iteself is const

```cpp
int x = 10;
int *const p = &x;

// the pointer p is const, can't change its point position, but can change its data

int *p2 = p; // Okay, top-level const can be ignored
```

### Low-level const: the object which be pointed or referenced is const

```cpp
int x = 10;
const int *p = &x;  // or int const *p = &x;

// the data which be pointed by pointer p can't be modified through *p, but the point position can be changed.

int *p2 = p;    // Error, this implicit conversion is forbidden, because we may modify the data through dereferencing p2 
```

### const_cast

- Can only modify the CV qualifiers(const and volatile) of expression. 
- Can't modify original type(like int -> double).

```cpp
const int* p = &x;
int* q = const_cast<int*>(p);   // remove low-level const

const int* p2 = &x;
const int* q2 = const_cast<const int*>(p2); // add const

const int a = 10;
int* b = const_cast<int*>(&a);     
*b = 20;        //error, UB
```

---

## noexcept

Indicates that the function won't throw exception.

[CppNotes/C++11/noexcept](../../CppNotes/C++11/noexcept.cpp)

```cpp
void f() noexcept(noexcept(g()));   // conditional noexcept, indicates that if g() doesn't throw exception, then f() will not throw either
```

Why move constructor need noexcept?

Because vector should guaranteen strong exception safety. If move constructor has the possibility of exception, it would rather call copy constructor.
