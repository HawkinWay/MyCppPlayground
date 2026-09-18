#include <iostream>

// (args + ...) -> (a1 + (a2 + (a3 + ...)))     unary right fold
// (... + args) -> (((a1 + a2) + a3) + ...)     unary left fold
// (t + ... + args) -> (((t + a1) + a2) + ... + an)   binary right fold
// (args + ... + t) -> (a1 + ((a2 + a3) + (... + t)))     binary left fold

// (... op pack) -> (((a1 op a2) op a3)...)       unary left fold
// (pack op ...) -> (a1 op (a2 op (a3 ...))       unary right fold
// (init op ... op pack) -> (((init op a1) op a2)...)   binary left fold
// (pack op ... op init) -> (a1 op (a2 op (... op init)))   binary right fold

// Before C++17, we can use recursive variadic template to implement a sum function
template<typename T>
T sum1(T&& t){
    return t;
}

template<typename T1, typename T2, typename... Args>
auto sum1(T1&& t1, T2&& t2, Args&&... args){
    return sum1(t1 + t2, std::forward<Args>(args)...);
}


// C++17, we can use fold expression
template<typename T, typename... Args>
auto sum2(T&& t, Args&&... args){
    return (t + ... + args);   // fold expression
}

int main(){
    std::cout << sum1(1) << sum1(1, 2) << sum1(1, 2, 3) << '\n'; // 136
    // sum1(1, 2, 3) -> sum1(3, 3) -> sum1(6) -> 6

    std::cout << sum2(1) << sum2(1, 2) << sum2(1, 2, 3) << '\n'; // 136
    // sum2(1, 2, 3) -> (1 + pack(2, 3)) -> ((1 + 2) + 3) -> 6
}