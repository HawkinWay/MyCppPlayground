#include<iostream>

// 虚继承：虚基类（A）由“最派生类”（D）直接初始化
// Virtual Inheritance: The virtual base class (A) is directly
// initialized by the "most derived class" (D).

// 虚函数表：编译器为有虚函数的类创建的一个静态数组，数组里存放着该类所有虚函数的地址。用于动态绑定虚函数
// Virtual function table: A static array created by the compiler for classes with virtual functions. 
// This array stores the addresses of all virtual functions in the class. 
// It is used for dynamically binding virtual functions.
// 虚函数表指针：编译器为每一个对象实例增加一个隐藏的指针成员。这个指针指向该类对应的虚函数表
// Virtual function table pointer: The compiler adds a hidden pointer member to each object instance. 
// This pointer points to the virtual function table corresponding to that class

// 虚函数的地址查找是“运行时”确定的，虚函数表的构建是“编译时”完成的
// The address lookup of virtual functions is determined "at runtime," 

// while the construction of the virtual function table is completed "at compile time."
struct A{
    A(int n){
        std::cout << "A" << n << " ";
    }
};

struct B : virtual A{
    B() : A(1){
        std::cout << "B ";
    }
};

struct C : virtual A{
    C() : A(2){
        std::cout << "C ";
    }
};

struct D : B, C{

    D() : A(3), B(), C(){
        std::cout << "D ";
    }
};

class Test{
public:
    Test() = default;
    ~Test(){
        std::cout << "~Test" << std::endl;
    }
    void print1(){
        std::cout << "print1" << std::endl;
    }
    virtual void print2(){
        std::cout << "print2" << std::endl;
    }
};

int main(){
    std::cout << "D: " << std::endl;
    D d;    
    // A3 B C D
    
    std::cout << "\nTest: " << std::endl;
    {
        Test *t = nullptr;  // 't' is null pointer, no object was created
        t->print1();
      /*t->print2();*/

        // print2是虚函数，通过虚函数表进行定位。而虚函数表的的指针需要对象创建才有，
        // 因此空指针调用虚函数无法找到虚函数表，因而会出现异常。
        // "print2" is a virtual function, located through the virtual function table.
        // Since a pointer to the virtual funciton table is only available upon object creation,
        // a null pointer exception will occur because the virtual function table
        // cannot be found when calling a virtual funtion.
    }
    std::cout << "I'm OK" << std::endl;
    // print1
    // I'm OK

    std::cin.get();
}
