#include <iostream>
#include <functional>
#include <thread>

#if 0
class __Lambda_xxx {
private:
    int x;   // if capture value
//  int &x;  if capture reference
public:
    __Lambda_xxx(int x_) : x(x_) {}
    int operator()(int y) const { return x + y; }
};

__Lambda_xxx lam(x);
#endif

// # 1
std::function<int()> make(){
    int x = 42;
    return [&x](){ return x; };
}

// # 2
void start(){
    int counter = 0;
    std::thread trd([&counter](){ 
        for(int i = 0; i < 100; i++)    counter++;
    });
    trd.detach();
}

// # 3
class FOO{
private:
    int val_{100};
public:
    std::function<int()> get(){
        return [this](){ return val_; };    // in C++17, we can write [*this] to capture a copy of the object, this is safe
    }
};

int main(){
    // # 1
    auto f = make();
    std::cout << f();   // UB, x is destroyed, but the lambda still holds a reference to x

    // # 3
    std::function<int()> f;
    {
        FOO foo;
        f = foo.get();
    }   // foo destroyed
    std::cout << f();

    // # 4
    int x{0};
    auto fc = [x](){ x++; }; // Error, lambda operator() is default const, cannot modify member x
    auto fc2 = [x]() mutable { x++; }; // OK, but the limit is fc2 cannot be const, because const object can only call const function

}