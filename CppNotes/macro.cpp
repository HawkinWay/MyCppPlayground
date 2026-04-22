#include<iostream>
#include<string>

#define LOG(x) std::cout << x << std::endl
#define LOG2(x) std::cout << x << std::endl;

#if 0
0 means flase
The area between them is equivalent to being deleted or commented out
#endif

// '\' means escape character newline
// DO NOT add space ‘ ’ after '\' if you want to add a new line 
#define PRINT void print() \
{\
	std::cout << "PRINT_void_print()" << std::endl;\
}

PRINT

int main(){
	LOG("Hello");
	LOG2("Hello2")	// notice, here doesn't need ';'
	
	std::cin.get();
}

