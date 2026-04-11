#include<iostream>

// Right-to-Left Rule

// Treat everything after the asterisk as a single unit.
// const int *[p], int const *[p], int *[const p], const int *[const p]

// 1
// Pointer to Constant Integer: 'const int *p' or int const *p'
// The data being pointed to is constant.

// 2
// Constant Pointer to Integer: 'int *const p'
// The pointer address itself is constant.


// 3 
// Constant Pointer to a Constant Integer: 'const int *const p'
// Everything is read-only.

int main(){
	int i = 10;
	int j = 1;
	const int *p1; // (1)
	int const *p2 = &i; // (2)
	p2 = &j; //(3)
	int *const p3 = &i; // (4)
	*p3 = 20; // (5)
//  *p2 = 30; // (6) error
//   p3 = &j; // (7) error

	std::cin.get();
}
