// a compile time performed assert

// static_assert(constant_expression, "Error message");
// static_assert(constant_expression);	C++17
// if constant_expression is false, then the compiler output specified the statement(if u writed)
// and fail to compile, ERROR is C2338. Otherwise, the statement is invalid

#include<array>

int main(){
	std::array<int, 11> arr;
	static_assert(arr.size() <= 11, "Size is too large!");
	// if arr.size() > 11, will trigger the assertion
}
