#include "thrd.h"
#include<iostream>

int main(){
	Genshen::Foo foo;
	
	std::thread sing([&](){ foo.print(); });
	sing.join();

	std::cin.get();
}
