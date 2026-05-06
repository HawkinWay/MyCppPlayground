#include<thread>
#include<vector>
#include<iostream>
#include<memory>

class Entity{
public:
    void print(){
        std::cout << "haha" << std::endl;
    }
};

void print(size_t& i){
    std::cout << "i: " << i++ << "\n";
}

int main(){
    // if we use reference, we should use std::ref
    // std::thread p1(print, 1);    error, 1 is a temporary variable, will be destroyed immediately
    int a = 1;
    std::thread p1(print, std::ref(a));
    
    std::shared_ptr<Entity> entity = std::make_shared<Entity>();
#if 0
    std::thread t(Entity::print, entity);   //error, call to non-static member function without an object argument
#endif
    // The fixed syntax for obtaining the address of a member-function in C++ is: &ClassName::FunctionName.  & get address
    std::thread t(&Entity::print, entity);
    t.join();
}