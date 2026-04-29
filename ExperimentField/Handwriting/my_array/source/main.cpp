#include "../include/my_array.h"
#include<iostream>
#include<stdio.h>


template<typename T>
void print(const T& arr){
	for(const auto& i : arr){
		std::cout << i << " ";
	}
	std::cout << '\n';
}

template<typename T>
void getAt(const T& a){
	std::cout << a << '\n';
}

void test(const Shovy::array<int, 5>& const_arr) {
    getAt(const_arr.at(0)); // This MUST call the const version
}

#define p print(arr)
#define p2 print(arr2)

int main(){
	Shovy::array<int, 5> arr{1,2,3,4,5};
	arr.at(1);
	p;
	arr.at(0) = 6;
	p;
	printf("test(arr):");
	test(arr);	// call 'const T& at (size_t) const;

	// arr.at(5);
	// p;
	// printf("%d",arr.front());
	// printf("%d",arr.back());
	std::cout << "Front: " << arr.front() << "\n";
    std::cout << "Back: " << arr.back() << "\n";
    std::cout << "is empty? " << (arr.empty() ? "yes" : "no") << "\n";

	Shovy::array<int, 3> arr2;
	p2;
	arr2.fill(4);
	p2;


}
