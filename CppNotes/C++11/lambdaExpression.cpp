#include<iostream>
#include<vector>
#include<functional>

void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

void HelloWorldValue(int a) {
    std::cout << "Hello World! The value: " << a << std::endl;
}

void Print(int value) {
    std::cout << "value: " << value << std::endl;
}

void ForEach(const std::vector<int> &nums, void(*functionPrint)(int)) {
    for (auto i : nums) {
        functionPrint(i);
    }
}

void ForEach2(const std::vector<int>& nums, const std::function<void(int)> func) {
//std::function<void(int)> means store a  callable object that returns void and accepts an int parameter
    for (auto i : nums) {
        func(i);
    }
}

int main() {
    //function pointers
    //////////////////////////////////////////
    std::cout << "//use auto: " << std::endl;
    auto functionType1 = HelloWorld;            //the type of functionType is: void(*functionType)()
    functionType1();

    std::cout << "\n//use void(* )(): " << std::endl;
    void(*functionType2)() = HelloWorld;
    functionType2();

    std::cout << "\n//use typedef: " << std::endl;
    typedef void(*HelloWorldFunction)();
    HelloWorldFunction functionType3 = HelloWorld;
    functionType3();
    std::cout << std::endl;

    //////////////////////////////////////////
    std::cout << "\n//use void(* )(int):\t\t//with a value" << std::endl;
    void(*functionType4)(int) = HelloWorldValue;
    functionType4(3);
    functionType4(6);
    functionType4(9);

    std::cout << "\nuse typedef:\t\t//with a value" << std::endl;
    typedef void(*HelloWorldValueFunction)(int);
    HelloWorldValueFunction functionType5 = HelloWorldValue;
    functionType5(4);
    functionType5(8);
    std::cout << std::endl;


    //////////////////////////////////////////
    std::cout << "\nuse function pointer to print: " << std::endl;
    std::vector<int> nums = { 2,5,4,8 };
    ForEach(nums, Print);

    //lambda
    //////////////////////////////////////////
    std::cout << "\nuse lambda writing style: " << std::endl;
    ForEach(nums, [](int value) {std::cout << "value: " << value << std::endl; });

    std::cout << "\nuse lambda writing style: " << std::endl;
    auto lamb = [](int value) {std::cout << "value: " << value << std::endl; };
  //if remove auto, and the [] is empty, this function should be like: 
  //void(*lamb)(int) = [](int value) {std::cout << "value: " << value << std::endl; };
  //this function equals to: 
  //void lamb(int value){std::cout << "value: " << value << std::endl; }
    ForEach(nums, lamb);
    std::cout << std::endl;

    //////////////////////////////////////////
    int a = 4, b = 5;
    //[=] pass everything by value
    //[&] pass everything by reference
    //[a] capture value        *can't revise the value of a
    //[&a] capture reference   *this will revise the value of a
    auto lambA = [a]() {std::cout << "lambA a: " << a << std::endl; };
    auto lambB = [&b]() {std::cout << "lambB b: " << b++ << std::endl; };
    lambA();
    lambB();
    std::cout << "a: " << a << "\nb: " << b << std::endl;
}