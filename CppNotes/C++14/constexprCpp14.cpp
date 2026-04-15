#include<iostream>

// variable with 'constexpr' is constant
// function with 'constexpr' in C++11: implicit 'const'
//                           in C++14: no longer implicit 'const', allow the use of 'if', 'switch', 'for', 'while', recursion, etc.

class Foo{
public:
    constexpr Foo(int i) : _i(i){}
    constexpr int GetValue() const{     // in C++14, if you don't add 'const' here, it will cause an error at #1 in the current file
        return _i;
    }
private:
    int _i;
};

int main(){
    constexpr Foo f(5);     // #1 object f is const, if GetValue() not const, f can't call it

    std::cout << "f.GetValue(): " << f.GetValue() << std::endl;

    std::cin.get();
}