#include<iostream>

// static 自由函数具有内部链接（Internal Linkage）,不会被其他翻译单元(Translated Unit)看到
// 对于非类成员，尽量在.cpp中使用static以减少符号污染，在.h中使用static function会导致包含它的每一个翻译单元都有一个独立副本
// 惰性初始化(Static Lazy Initialization): 在 C++11 及更高版本中，在函数内部声明的静态局部变量是线程安全且惰性初始化的。只有当代码执行到该声明行时，变量才会被创建。

class Entity{
public:
    int x, y;
    // static member-variables should be decalred inside the class and defined outside the class.
    static int m, n;

    // static meber-function can only call static member-variables, can be defined inside the class.
    // static void print(){
    //     std::cout << x << ", " << y << std::endl;
    // }
    static void print(){
        std::cout << m << ", " << n << std::endl;
    }
    static void print(Entity e){
        std::cout << e.x << ", " << e.y << std::endl;
    }
};
int Entity::m = 0;
int Entity::n = 1;

static void print(Entity e){
    std::cout << e.x << ", " << e.y << std::endl;

}

int main(){
    Entity entity;
    entity.x = 1;
    entity.y = 2;
    entity.m = 3;
    entity.n = 4;
    std::cout << "\nentity.print():" << std::endl;
    entity.print();
    std::cout << "\nentity.print(entity):" << std::endl;
    entity.print(entity);

    std::cout << "\nprint(entity):" << std::endl;
    print(entity);
    
}