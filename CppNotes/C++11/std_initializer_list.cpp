#include <iostream>

#include <initializer_list>

// If a class has initializer_list contructor, {} initialization will give priority to the contructor, even if a narrowing conversion would result in an error.

// underlying implementation
template<typename T>
class initializer_list{
private:
	const T* __begin;
	size_t __size;
public:
	const T* begin() const;
	const T* end() const;
	size_t size() const;
};



void func(std::initializer_list<int> il){
	for(int x : il)
		std::cout << x << ' ';
}

std::initializer_list<int> func2(){
	return {1, 2, 3};	// danger, this only copy the pointer. the underlying array is a temporary object and will be destroyed after function ends.
}

int main(){
	func({1, 2, 3});
	auto x = {1, 2, 3};	// x: std::initializer_list<int>
	auto il = func2();	// UB, il dangling

	
	std::vector<int> v{1, 2.5};	// error, 2.5 narrowing converse into int
}
