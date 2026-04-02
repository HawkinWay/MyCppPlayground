#include<iostream>
#include<memory>

class Entity {
public:
    Entity() {
        std::cout << "constructor Entity." << std::endl;
    }
    ~Entity() {
        std::cout << "destructor Entity." << std::endl;
    }
    void Print() {
        std::cout << "Print() function is called." << std::endl;
    }
};

int main() {
    //////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<Entity> entity(new Entity());
    
    /*std::unique_ptr<Entity> entity = new Entity();        
    this writing style is WRONG!
    because the constructor of unique_ptr is explicit
    */
    
    /*std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    this writing styled is safer
    if your constructor throws error
    */

    entity->Print();
    std::cout << std::endl;
    
    /*std::unique_ptr<Entity> entity2 = entity;
    this writing style is WRONG!
    because unique_ptr can't be copied
    */
    

    //////////////////////////////////////////////////////////////////////////////
    std::shared_ptr<Entity> entityShared = std::make_shared<Entity>();
    std::shared_ptr<Entity> entityShared2 = entityShared;        //increased reference counting

    std::cout << "enetityshared: " << std::endl;
    entityShared->Print();
    
    // if everything concerned to shared_ptr are destructed, the original shared_ptr will then call destructor
    // like: when entityShared2 called destructor, entityShared wouldn't call destructor



    //////////////////////////////////////////////////////////////////////////////
    
    std::weak_ptr<Entity> entityWeak = entityShared;
    //when use weak_ptr copies shared_ptr, the reference count won't increase
    /* std::make_weak is not exist */


}