# New Features

- [auto, decltype](../../CppNotes/C++11/auto&decltype.cpp), nullptr
- [rvalue reference, move semantics](../../CppNotes/C++11/std_move.cpp), collapse reference, [perfect forward](../../CppNotes/C++11/std_forward.cpp)
- [lambda](../../CppNotes/C++11/lambdaExpression.cpp), [lambda errors](../../CppNotes/C++11/lambdaErrors.cpp), [std::function](../../CppNotes/C++11/std_function.cpp), [std::bind](../../CppNotes/C++11/std_bind.cpp)
- [variadic template](../../CppNotes/C++11/variadicTemplate.cpp)
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
    - std::string_view
    - [Fold expession](../../CppNotes/C++17/foldExpression.cpp), [variadic template Cpp17](../../CppNotes/C++17/variadicTemplateCpp17.cpp)
- C++20
    - erase_if
    - constinit
    - conteval
    - ranges
    - concepts
    - coroutine

---

## auto vs decltype

- auto will discard top-level const and reference: const int* const p -> auto -> const int* p
- [decltype(expr)](../../CppNotes/C++11/auto&decltype.cpp)

---

- lvalue
- rvalue
    - prvalue
    - xvalue

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