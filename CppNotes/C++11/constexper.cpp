#include<iostream>

// 如果一个变量在编译期就定死了，那它在运行时逻辑上就不应该被修改。

// The purpose of a constexpr function is to produce a constant at compile time.
// This uses less memory and helps your program run faster.

// 1. All constexpr vriables are const.
// 2. Member-function with 'constexpr' should be declared and defined in .h
//    Because every translate unit is independent, they don't know each other
//    If the compiler only sees the declaration of GetValue() but not its definition(like GetValue() declared in foo.h and be pasted with include "foo.h" in main.cpp, but it's definition in foo.cpp) when compiling main.cpp, 
//    it will not be able to calculate the result at compile time.
// 3. A variable can be declared with constexpr, when it has a literal type and is initialized. 
// 4. In C++11, a constexpr function can only have one return statement

// godbolt.org


constexpr int adder(int a, int b){
	return a + b;
}

class Foo{
private:
	int _i;
public:
	constexpr explicit Foo(int i) : _i(i){}
	constexpr int GetValue() /*const*/{		// in C++11, the member-function which with constexpr is impliciting const 
		return _i;
	}
};

int main(){
	constexpr int i = adder(9, 11);

	constexpr int i; // error, not initialized
	int j = 0;
	constexpr int k = j + 1; // error, j not a constant expression 
	
	constexpr Foo f(5);

	// run time:
	std::cout << "f.GetValue()" << f.GetValue() << std::endl;

	std::cin.get();
}
