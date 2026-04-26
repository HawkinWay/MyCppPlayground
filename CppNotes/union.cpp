// similar to classes and structs, but every member in union shared same memory location
// A union can be useful for conserving memory when you have lots of objects and limited memory.

// struct Foo{ int x, y; };	4byte * 2 = 4byte
// union Bar{ int x, y; };	4byte

#include<iostream>

union Foo{
	float a;
	int b;
};

struct Bar{
	int x, y;
	union{		// anonmyous union, have no member-function and private/potected membe(when in class/struct)
		float speed;
		int id;
		uint32_t bin;
	};
};

struct FK{
	float x, y;
};

struct What{
	union{
		struct{
			float x, y, z, w;
		};
		struct{
			FK a, b;	// a: x,y	b: z,w
		};
	};
};

void print(const FK& fk){
	std::cout << fk.x << ", " << fk.y << std::endl;
}

int main(){
	Foo foo;
	foo.a = 5.f;
	foo.b = 7;

	Bar bar;
	bar.speed = 1.5f;
	std::cout << "bar.speed = 1.5f, let's see bar.id: " << bar.id << "\nbar.bin: " << bar.bin << std::endl;

	What what = {1.f, 2.f, 3.f, 4.f};
	print(what.a);
	print(what.b);
	what.z = 48.f;
	print(what.a);
	print(what.b);
}
