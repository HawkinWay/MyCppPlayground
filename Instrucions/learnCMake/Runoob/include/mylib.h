#pragma once

#include<iostream>

namespace JB{
class Foo{
private:
	int a, b;
public:
	constexpr Foo(int a, int b) : a(a), b(b){}
	int getA() const;
	int getB() const;
	int adder() const;
};
}
