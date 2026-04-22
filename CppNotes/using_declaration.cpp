#include<stdio.h>
#include<iostream>

class B{
public:
	void f(char){
		printf("In B::f()\n");
	}
	void g(char){
		printf("In B::g()\n");
	}
};

class C{
public:
	int g();
};

class D : /*private*/B{
public:
	using B::f;	// B::f(char) is now visible as D::f(char)
	using B::g;	// B::g(char) is now visible as D::g(char)
	void f(int){
		printf("In D::f()\n");
		f('c');	//Invokes B::f(char) instead of recursing
	}	
	void g(int){
		printf("In D::g()\n");
		g('c');	//Invokes B::g(char) instead of recursing
	}
};

class D2 : public B{
public:
	using B::f;	
  //using C::g;		error, C isn't a base of D2
};

void f(){
	printf("In f()\n");
}

namespace A{
	void g(){
		printf("In A::g()\n");
	}
}

namespace X{
	using ::f;		// global f is also visible as X::f
	using A::g;		// A's g is now visible as X::g	
}

void h(){
	printf("In h\n");
   	X::f();   // calls ::f
   	X::g();   // calls A::g
}

namespace B{
	int i;
	void f(int);
	void f(double);
}

void g(){
	int i;
  //using B::i;		error, i declared twice
	void f(char);
	using B::f;		// right
}

int main(){
	D myD;
	std::cout << "\nmyD.f(1): ";
	myD.f(1);
	std::cout << "\nmyD.f('a'): ";
	myD.f('a');
	std::cout << "\nmyD.g(1): ";
	myD.g(1);
	std::cout << "\nmyD.g('a'): ";
	myD.g('a');
	
	D2 myD2;
	std::cout << "\nmyD2.f(1): ";
	myD2.f(1);
	std::cout << "\nmyD2.f('a'): ";
	myD2.f('a');

	std::cout << "\nh():";
	h();
}
