// a function adapter
// "wrap" an existing function and transform it into a function object of a different kind.

// `std::bind` defaults to pass-by-value. If you want to bind to a reference, you must use `std::ref` or `std::cref`.

#include<iostream>
#include<functional>

void print(int a, int b){
	std::cout << a + b << std::endl;
}

int main(){
	auto add10 = std::bind(print, 10, std::placeholders::_1);
	auto add10Lamb = [](int b) { return print(10, b); };
	add10(5);	// print(10, 5)
	add10Lamb(5);
}

