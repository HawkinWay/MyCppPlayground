// #1 alias
// use an alias declaration to declare a name to use as a synonym for a previously declared type.

// Syntax
// using identifier = type;

// An alias doesn't introduce a new type and can't change the meaning of an existing type name.
// C++03
typedef long counter03;
typedef void (*func03)(int);
// C++11
using conter11 = long;
using func11 = void(*)(int);
template<typename T> using ptr = T*;    // typedef mechanism doesn't work with templates

ptr<int> ptr_int;

void foo(int arg){}
func03 f03 = &foo;
func11 f11 = &foo;

// #2 typedef

typedef unsigned long UL;
int UL;		// error, redefined

typedef void DRAWF(int, int);
DRAWF box;	// void box(int, int);

typedef struct mystructtag{
	int i;
	double f;
}mystruct;

int main(){
	unsigned int UL;	// local variable, redeclaration hides typedef name
	mystruct ms;
	ms.i = 10;
	ms.f = 0.99;
}

// OK, name REGS redeclared by typedef name with the same meaning
typedef union REGS{
	struct wordregs x;
	struct byteregs h;
} REGS;

// file1.h
typedef char FOO;
typedef int BAR;
// file2.h
typedef char FOO;
typedef double BAR;
// prog.cpp
#include "file1.h"
#include "file2.h"
// FOO is ok, it likes typedef CHAR CHAR;
// BAR is error, can't redefine a name that was previously declared as a different type
