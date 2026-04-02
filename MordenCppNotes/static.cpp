#include<iostream>

class Entity{
public:
    int x, y;
    static int m, n;
    static void print(){
        //std::cout << x << ", " << y << std::endl;   // x, y wrong
    }
    static void print(){
        std::cout << m << ", " << n << std::endl;
    }
    static void print(Entity e){
        std::cout << e.x << ", " << e.y << std::endl;
    }
};

static void print(Entity e){
    std::cout << e.x << ", " << e.y << std::endl;

}

int main(){
    Entity entity;
    entity.x = 1;
    entity.y = 2;
    entity.m = 3;
    entity.n = 4;
    entity.print();
    
}