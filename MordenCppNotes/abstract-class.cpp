#include<iostream>

class Shape{
public:
    virtual double area() = 0;
};

class Square : public Shape{
public:
    double side;
    
    Square(double side) : side(side){

    }

    double area(){
        return side * side;
    }
};

class Triangle : public Shape{
public:
    double base;
    double height;
    
    Triangle(double base, double height) : base(base), height(height){

    }

    double area(){
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