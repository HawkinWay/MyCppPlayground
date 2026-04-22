#include<iostream>

class Shape{
public:
    virtual double area() = 0;      
    virtual ~Shape() = default; // 虚析构函数，能让基类指针删除子对象
    // virtual function() = 0 定义纯虚函数
    // function = default 显示缺省，让编译器生成这个函数的默认版本。只能用于默认构造函数、析构函数、拷贝构造/赋值、移动构造/赋值
    // function = delete 显示仅用某个函数，常用语禁止特定的构造函数、拷贝构造和赋值构造 
    // Entity(double) = delete;
    // Entity(const Entity&) = delete; 
    // Entity& operator = (const Entity&) = delete;
};

class Square : public Shape{
public:
    double side;
    
    Square(double side) : side(side){

    }

    double area() override{
        return side * side;
    }
};

class Triangle : public Shape{
public:
    double base;
    double height;
    
    Triangle(double base, double height) : base(base), height(height){

    }

    double area() override{
        return 0.5 * base * height;
    }
};

int main(){
  //Shape s;  ❌ 不能实例化
    
    // ✅可以用指针或引用指向*子类对象*
    Shape *shape[] = {
        new Square(2),
        new Square(5),
        new Triangle(4, 2),
        new Triangle(5, 3)
    };

    for(auto &i : shape){
        std::cout << "shape " << i << " area: " << i->area() << std::endl;
    }

    for(auto i = 0; i < 4; i++){
        std::cout << "shape " << i << " area: " << shape[i]->area() << std::endl;
    }
}
