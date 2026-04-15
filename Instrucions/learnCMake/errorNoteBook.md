# cpp project structure

> Runoob/  
>   CMakeLists.txt  
>   include/  
>       mylib.h
>   src/  
>       mylib.cpp  
>       main.cpp

## mylib.h

> Runoob/include/mylib.h

头文件进行类与成员函数的声明

```mylib.h
#pragma once

#include<iostream>      // #inlcude写在namespace之前， #include<iostream>最好放在main.cpp里

namespace JB{

class Foo{
private:
    int a, b;

public:
    constexpr Foo(int, int);    // error, constexpr函数的定义必须放在头文件里 constexpr Foo(int a, int b) : a(a), b(b) {}
    int getA() const;
    int getB() const;
    int adder() const;
};

} 
```

## mylib.cpp

> Runoob/src/mylib.cpp

头文件对应的.cpp进行成员函数的实现

```mylib.cpp
#include "../include/mylib.h"   //注意路径的正确性

namespace JB{

Foo::Foo(int a, int b) : a(a), b(b){}   // error, constexpr函数的定义必须放在头文件里
// 普通成员函数可以留在 .cpp 中
int Foo::getA() const{return a;}
int Foo::getB() const{return b;}
int Foo::adder() const{return a + b;} 

}

```

## main.cpp

> Runoob/src/main.cpp

主程序只需包含.h，无需包含对应的.cpp

```main.cpp
#include "../include/mylib.h"

// #include<iostream>   .h中虽然已有，但此处再加也无妨，.h中的#pragma once可以防止重复包含


namespace JB{   // error，main函数不应该放在自定义命名空间里
                // 操作系统寻找的是全局作用域下的 main

int main(){
constexpr Foo foo{3, 6};    // error, Foo需要加命名空间作用域 JB::Foo
std::cout << "a: " << foo.getA() << "\nb: " << foo.getB() << "\na + b: " << foo.adder() << std::endl;

std::cin.get();
}

} 
```

---

## correct version

### mylib.h

```mylib.h
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
```

---

### mylib.cpp

```mylib.cpp
#include "../include/mylib.h"

namespace JB{
int Foo::getA() const{return a;}

int Foo::getB() const{return b;}

int Foo::adder() const{return a + b;}
}
```

---

### main.cpp

```main.cpp
#include "../include/mylib.h"
#include<iostream>

int main(){
	constexpr JB::Foo foo{3, 6};
	std::cout << "a: " << foo.getA() << "\nb: " << foo.getB()
		<< "\na + b: " << foo.adder() << std::endl;

	std::cin.get();
}
```

---

## **RUN THEM**

```bash
g++ mylib.cpp main.cpp -o main
./main
```

> The output result is:  
> a: 3  
> b: 6  
> a + b: 9  
 


