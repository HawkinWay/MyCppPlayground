#include "../include/mylib.h"
#include<iostream>

int main(){
	constexpr JB::Foo foo{3, 6};
	std::cout << "a: " << foo.getA() << "\nb: " << foo.getB()
		<< "\na + b: " << foo.adder() << std::endl;

	std::cin.get();
}

