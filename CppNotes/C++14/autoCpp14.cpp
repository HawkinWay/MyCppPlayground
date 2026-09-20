#include <iostream>

// Before C++14, auto cannot directly deduce the function return type, but trailing return type can be used
auto f() -> int{
    return 1;
}

template<typename T, typename U>
auto myFunc(T&& t, U&& u) -> decltype(t + u){
    return std::forward<T>(t) + std::forward<U>(u);
}

// In C++14, we can use auto to deduce the return type of a function
// but auto will discard top-level const and reference qualifiers
// so if we want to preserve them, we can use decltype(auto)

auto f2(){
    return 1;
}

template<typename T, typename U>
decltype(auto) myFunc2(T&& t, U&& u){
    return std::forward<T>(t) + std::forward<U>(u);
}

decltype(auto) dacauto(){
    static int x = 1;
    std::cout << "x address: " << &x << '\n';
    return (x); // return type is int&
}

int main(){
    std::cout << f() << '\n';
    std::cout << myFunc(1, 2) << '\n';
    std::cout << f2() << '\n';
    std::cout << myFunc2(1, 2) << '\n';
    auto& rx = dacauto();
    std::cout << "rx: " << &rx << '\n';
}