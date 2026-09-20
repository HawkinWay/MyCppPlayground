# New Features

- [auto, decltype](../../CppNotes/C++11/auto&decltype.cpp), nullptr
- [rvalue reference, move semantics](../../CppNotes/C++11/std_move.cpp), collapse reference, [perfect forward](../../CppNotes/C++11/std_forward.cpp)
- [lambda](../../CppNotes/C++11/lambdaExpression.cpp), [lambda errors](../../CppNotes/C++11/lambdaErrors.cpp), [std::function](../../CppNotes/C++11/std_function.cpp), [std::bind](../../CppNotes/C++11/std_bind.cpp)
- [variadic template](../../CppNotes/C++11/variadicTemplate.cpp)
- [SFINAE](../../CppNotes/C++11/SFINAE.cpp)
- [initializer_list](../../CppNotes/C++11/std_initializer_list.cpp)
- [constexpr](../../CppNotes/C++11/constexpr.cpp), [inline constexpr](../../CppNotes/C++17/inlineVariables.cpp)
- [using vs typedef](../../CppNotes/aliases_and_typedefs.cpp), alias template
- [smart_ptrs](SmartPtrs.md)
- [std::thread](../../CppNotes/C++11/multiThreading/std_thread.cpp), std::mutex, std::lock_guard, std::unique_lock
- uniformed initialization {}
- [noexcept](../../CppNotes/C++11/noexcept.cpp), override, final, default, delete

- C++14
    - [constexpr function](../../CppNotes/C++14/constexprCpp14.cpp): remove implicit const
    - [auto func(), decltype(auto)](../../CppNotes/C++14/autoCpp14.cpp)
    - [lambda](../../CppNotes/C++14/lambdaCpp14.cpp): generics  and initialized capture
- C++17
    - [std::optional](../../CppNotes/C++17/std_optional.cpp)
    - [std::variant](../../CppNotes/C++17/std_variant.cpp)
    - [std::string_view](../../CppNotes/C++17/std_string_view.cpp)
    - [Fold expession](../../CppNotes/C++17/foldExpression.cpp), [variadic template Cpp17](../../CppNotes/C++17/variadicTemplateCpp17.cpp)
    - [Structured binding](../../CppNotes/C++17/structuredBinding.cpp)
    - [If initialization](../../CppNotes/C++17/ifInitialization.cpp)
    - [[[nodiscard]]](../../CppNotes/C++17/nodiscard.cpp)
    - std::any
    - std::filesystem
    - if constexpr
- C++20
    - ***coroutine**: `co_wait`, `co_yield`, `co_return`
    - ***ranges**
    - [***concepts**](../../CppNotes/C++20/concepts.cpp)
    - ***modules**
    - erase_if
    - constinit
    - conteval
    - <=>
    - std::span

---

## 0, NULL, nullptr, nullptr_t, nullopt

`NULL`(0, 0L, __null) is a macro, a integer, not a pointer type.
So NULL and 0 are not fit for "null pointer" because they are not **type safe**. They may lead wrong overload and incorrect type inference.

`nullptr` is a *key word*, type is `std::nullptr_t`(not a integer), defined in `<cstddef>`. Can converse into nothing but bool, value is false. `sizeof(std::nullptr_t)` is always equal to `sizeof(void*)`.


`std::nullopt` is a constant introduced in C++17, type is `std::nullopt_t`, defined in `<optional>` (see [std::optional](../../CppNotes/C++17/std_optional.cpp)).  It only refers to "no value", has nothign to do with "null pointers".

---

## auto and decltype

- auto will discard top-level const and reference: const int* const p -> auto -> const int* p
- [decltype(expr)](../../CppNotes/C++11/auto&decltype.cpp)

- auto&&: universal reference

---

## constexpr

- C++ 11
    - implicit const and inline for function
    - do not support `for`, `while`, `if`, `switch`
    - can only have one return sentence
    - do not support local variable
- C++ 14
    - no more implicit const for function
    - constexpr function support `for`, `while`, `if`, `switch`
    - can have multiple return types
    - support local variable
- C++ 17
    - inline constexpr variable
    - if constexpr
    - contexpr lambda
- C++20
    - consteval, constinit
    - support `try/catch`
    - support `vector`, `string`

---

### expression

- gvalue (lvalue, xvalue)
- rvalue (prvalue, xvalue)

|Dimension|lvalue|prvalue|xvalue|
|--|--|--|--|
|Defination|has name, can acquiree address|literal, temporary object|about to be destroyed and movable object|
|Examples|`int x;` x is lvalue| 10, 9, "abc",...| x after std::move(x)|

---

### collapse reference

- lvalue-lvalue: T& &
- lvalue-rvalue: T& && (euqals to T&)
- rvalue-lvalue: T&& &
- rvalue-rvalue: T&& &&

> Using scenario is *perfect forward*, we can't write such references manually, but compiler can do this.

### universal reference

template T + T&&

```cpp
template<typename T>
Returntype Func(T&& param){

}
```

If we pass a lvalue, T is deduced to int&, so the param list:

```cpp
(int& && param)
```

Because of collapse reference:

```cpp
(int& param)
```

### perfect forwarding

Whatever we pass into Func(), the param is **lvalue** within Func(). Because param is a named object, so it is lvalue.

If we wanna remain the value type, we should use `std::forward`
```cpp
// std:::forward source code outline
template<typename T>
T&& forward(T& param){
    return static_cast<T&&>(param);
}
```

If we pass lvalue:
```cpp
int& && forward(int& &param){
    return static_cast<int& &&>(param);
}
```
Because int& && is int&(collapse reference), so we get a lvalue.

If we pass rvalue:
```cpp
int&& && forward(int&& &param){
    return static_cast<int&& &&>(param);
}
```
Because int&& && is int&&(collapse reference), so we get a rvalue.

---

## range-for loop

```cpp
for(auto& x : range){
    // do something...
}

{
    auto&& __range = range;
    auto __begin = begin(__range);
    auto __end = end(__range);
    for(; __begin != __end; ++__begin){
        auto& x = *__begin;
        // do something...
    }
}
```

> Notice: *When modify the size of container(like erase or push_back itself), iterator will be invalid.*

---

## std::move()

```cpp
// UB: dangling reference
std::vector<int>&& getData() {
    std::vector<int> v = {1, 2, 3};
    return std::move(v);   // return local variable's rvalue reference，v has been destructed -> dangling
}

// suboptimal
std::vector<int> getData() {
    std::vector<int> v = {1, 2, 3};
    return std::move(v);   // correct behaviour，but restrict NRVO
}

// best practice
std::vector<int> getData() {
    std::vector<int> v = {1, 2, 3};
    return v;   // compiler performs either NRVO (zero-overhead) or an automatic implicit move.
}

```

---
