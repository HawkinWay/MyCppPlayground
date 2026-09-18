#include <iostream>

// C++17 fold expression
// replace the recursive unfolding in C++11/14

template<typename... Arguments>
void print(Arguments&&... args){
    (std::cout << ... << args) << '\n'; // ((std::cout << a1) << a2) << a3;
}

int main(){
    print(1, 2, '3', "4, 5", 6.0, 7.f);     // 1234, 567
}