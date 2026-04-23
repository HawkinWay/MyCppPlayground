// # the rule of 0
#include<iostream>
#include<memory>
#include<algorithm>

class Entity{
private:
    int _size;
    std::unique_ptr<int[]> data;
public:
    explicit Entity(int s) : _size(s), data(std::make_unique<int[]>(s)){
        std::cout << "constructor" << std::endl;
    }

    // The following can all be omitted
    ~Entity() = default;
    Entity(Entity&&) = default;
    Entity& operator=(Entity&&) = default;

    void printInfo() {
        std::cout << "Size: " << _size << ", Data address: " << data.get() << std::endl;
    }
};

int main(){
    Entity foo(10);
    foo.printInfo();
}