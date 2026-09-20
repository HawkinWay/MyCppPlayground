// auto variable must be initialized at the time of declaration
// auto will discard top-level const and reference qualifiers

// decltype(expression)
// If expression is a variable or member access without parentheses, decltype gets its declared type and remains const and reference
// Otherwise, decltype derives the value type of the expression: 
//      lvalue expression yields T&
//      xvalue expression yields T&&
//      prvalue expression yields T

#include <iostream>

int main(){
    auto x = 2; // int
    auto s = "hello"; // const char*
    
    // auto will discard top-level const
    const int *const p = &x;
    auto q = p; // const int *p
    auto p2 = const_cast<int*>(p);  // int* p2
    const float y = 4.f;
    auto y2 = y;    // float


    decltype(x); // int
    decltype((x)); // int&
    decltype(y); // const float
    decltype((y)); // const float&
    int& xr = x;
    int&& r = 2;
    decltype(xr); // int&
    decltype((r)); // int&&
}