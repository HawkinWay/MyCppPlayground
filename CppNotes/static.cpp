#include<iostream>

class Entity{
public:
    int x, y;
    static int m, n;

    // static functino can only call static variables
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