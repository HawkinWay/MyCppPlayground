#include<iostream>
#include<memory>

struct vec {
	float x, y, z;
	vec() :x(10), y(20), z(30) {};
};

int main() {

	//stack RAM
	int val = 5;
	int arr[5] = { 1,2,3,4,5 };
	vec vc;

	//heap RAM
	int *hval = new int;
	*hval = 5;
	int *harr = new int[5];
	harr[0] = 1;
	harr[1] = 2;
	harr[2] = 3;
	harr[3] = 4;
	harr[4] = 5;
	vec *hvc = new vec();		//vec *hvc = new vec;

	std::unique_ptr<int> uptr = std::make_unique<int>();
	std::unique_ptr<int> uptr2(new int); 
}