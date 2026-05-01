// construct object in existing memory
// need explicit call deconstructor at the end of object's lifetime
// can't call 'delete' to release memory at the end of object's lifetime

// syntax
// T* ptr = new (address) T(arguments...);

#include<new>

struct Point{

};

int main(){
	char buf[sizeof(Point)];
	Point* p = new (buf) Point(10, 20);

	p->~Point();
}
