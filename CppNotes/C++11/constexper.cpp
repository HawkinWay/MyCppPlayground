#include<iostream>

// The purpose of a constexpr function is to produce a constant at compile time.
// This uses less memory and helps your program run faster.

// All constexpr vriables are const.
// A variable can be declared with constexpr, when it has a literal type and is initialized. 

// godbolt.org


constexpr int adder(int a, int b){
	return a + b;
}

class Foo{
private:
	int _i;
public:
	constexpr explicit Foo(int i) : _i(i){}
	constexpr int GetValue() const{
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
