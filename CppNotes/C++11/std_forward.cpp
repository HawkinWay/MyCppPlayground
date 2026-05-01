// before C++11, generic functions cannot preserve their raw type when passing arguments
// Perfect Forwarding can preserve the raw type(lvalue or rvalue) when passing arguments and avoid unnecessary copying and overhead
// std::forward is only designed to handle one thing at a time

#include<iostream>

void process(const int& x){
	std::cout << "lvalue reference: " << x << std::endl;
}


void process(int&& x){
	std::cout << "rvalue reference: " << x << std::endl;
}

template<typename T>
void forwardExample(T&& arg){	// Universal Reference = rvalue reference + template
	std::cout << "----------------normal passing" << std::endl;
	process(arg);
	std::cout << "----------------Perfect Forward passing" << std::endl;
	process(std::forward<T>(arg));
}

int main(){
	int n = 10;
	std::cout << "pass lvalue: \n";
	forwardExample(n);	// pass lvalue
	std::cout << "pass rvalue: \n";
	forwardExample(10);	// pass rvalue
}
