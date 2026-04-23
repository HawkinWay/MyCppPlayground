#include<iostream>

typedef void(*ptf)();

void func(){ std::cout << "111" << std::endl;}

struct S{
	operator ptf(){ return func; }
};

int main(){
	S s;
	s();	//operates as s.operator ptf()()
}
