#include <iostream>
#include<memory>
#include<functional>

// generic lambda
auto add = [](auto a, auto b){ return a + b; };  

int main(){
    std::cout << add(1, 2) << '\n';
    std::cout << add("a", "e");

    // initialized capture
    auto p = std::make_unique<int>(3);
    auto f = [p = std::move(p)](){ return *p; };

    // recursive lambda 
    // before C++14
    auto fib = [](auto&& self, int n) -> int{
        return n < 2 ? n : self(self, n - 1) + self(self, n - 2);
    };

    std::cout << fib(fib, 10);

    // C++14
    std::function<int(int)> fact = [&fact](int n){
        return (n <= 1) ? 1 : (n * fact(n - 1));
    };
}