# Basic Grammer

- inline
- static
- const
- constexpr
- noexcept

---

## inline

[CppNotes/inline.cpp](../../CppNotes/inline.cpp)  
[CppNotes/C++17/inlineVariables.cpp](../../CppNotes/C++17/inlineVariables.cpp)

---

## static

[CppNotes/static/static.cpp](../../CppNotes/static/static.cpp)  
[CppNotes/static/static_function.cpp](../../CppNotes/static/static_function.cpp)

### 1. static variables

1.1  static global variable

> *Stored in static section (usually, uninitialized/0 in .bss, initialized non-zero in  .data. This depends on you compiler)*

- Lifecycle is as same as normal global variable, which is the entire program; the difference lies in their **linkage**. This can **prevent naming conflicts**.

2.2 static local variable

- Thread safe since C++11 (magic static)
- Initialized once, lifecycle is the whole program
- Scope within the function


### 2. class static members

2.1 static member variable

- Belong to the class instead of an object.
- Does not occupy object size.
- Must be defined outside the class before C++17;
- Lifecycle is the whole program

2.2 static member fucntion

- Belong to the class instead of an object.
- **Have no** `this` pointer. So it can't be const, volatile and virtual.
- Can't call non-static member variable/function.

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

## constexpr

[CppNotes/C++11/constexpr.cpp](../../CppNotes/C++11/constexpr.cpp)

constexpr function can be calculated in compile-time or runtime

---

## noexcept

Indicates that the function won't throw exception.

[CppNotes/C++11/noexcept](../../CppNotes/C++11/noexcept.cpp)

```cpp
void f() noexcept(noexcept(g()));   // conditional noexcept, indicates that if g() doesn't throw exception, then f() will not throw either
```

Why move constructor need noexcept?

Because vector should guaranteen strong exception safety. If move constructor has the possibility of exception, it would rather call copy constructor.
