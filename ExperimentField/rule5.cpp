// # the rule of 5
#include<iostream>
#include<algorithm>

class Entity{
private:
    int _a;
    int *p;
public:
    Entity(int a) : _a(a), p(new int[a]){
        std::cout << "constructor" << std::endl;
    }

    ~Entity(){ 
        std::cout << "destructor" << std::endl;
        delete[]p; 
    }

    Entity(const Entity &other) : _a(other._a), p(new int[other._a]){
        std::cout << "copy constructor" << std::endl;
        std::copy(other.p, other.p + _a, p);
    }

    Entity& operator=(const Entity &other){
        std::cout << "copy assignment constructor" << std::endl;
        if(this != &other){
            delete[]p;
            _a = other._a;
            p = new int[other._a];
            std::copy(other.p, other.p + _a, p);
        }
        return *this;
    }

    Entity(Entity &&other) noexcept : _a(other._a), p(other.p){
        std::cout << "move constructor" << std::endl;
        other._a = 0;
        other.p = nullptr;
    }

    Entity& operator=(Entity &&other){
        std::cout << "move assignment constructor" << std::endl;
        if(this != &other){
            delete[]p;
            _a = other._a;
            p = other.p;
            other._a = 0;
            other.p = nullptr;
        }
        return *this;
    }
};

int main(){
    Entity foo(10);
    
    Entity bar1(foo);
    Entity bar2 = foo;

    Entity hi(5);
    hi = foo;

    Entity m1(std::move(bar1));
    Entity m2 = std::move(bar2);

    Entity n1(8);
    n1 = std::move(hi);

    Entity n2(7);
    n2 = 14;        // 先为14生成临时对象，是一个右值

    Entity n3(6);
    n3 = std::move(12); // 12本身就为右值，通过隐式构造生成临时 Entity(12), 多此一举

    // 如果你不希望 n2 = 14 这种偷偷摸摸的饮食转换行为编译通过，你应该在构造函数前加上 explicit
}

/*
output:

constructor                     foo

copy constructor                bar1
copy constructor                bar2

constructor                     hi
copy assignment constructor     hi

move constructor                m1
move constructor                m2

constructor                     n1
move assignment constructor     n1

constructor                     n2
constructor                     14
move assignment constructor     n2
destructor                      14

constructor                     n3
constructor                     12
move assignment constructor     n3
destructor                      12

destructor                      n3
destructor                      n2
destructor                      n1
destructor                      m2
destructor                      m1
destructor                      hi
destructor                      bar2
destructor                      bar1
destructor                      foo
*/
