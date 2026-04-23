# Rule of three
*the big three/the rule of the big three*

prior to C++11  
If a class defines any of the following then it should probably explicitly define all three:  

> - destructor  
> - copy constructor  
> - copy assignment operator  

If one of these functions is used without first being declared by the programmer it will be implicitly implemented by the compiler with default semantics.



# Rule of five
*the rule of the big five*

With the move senantics implemented in C++11, the rule of three can be broadened to the rule of five: 

> - destructor  
> - copy constructor  
> - copy assignment operator  
> - move constructor  
> - move assignment operator


Example code:

```cpp
#include<iostream>
#include<algorithm>

class Entity{
private:
    int _a;
    int *p;
public:
    Entity(int a) : _a(a), p(new int[a]){}

    // destructor
    ~Entity(){ delete[]p; }

    // copy constructor
    Entity(const Entity &other) : _a(other._a), p(new int[other._a]){
      //std::copy(start, end, newContianer)
        std::copy(other.p, other.p + _a, p);
    }

    // copy assignment constructor
    Entity& operator=(const Entity &other){
        if(this != &other){     // The judgment condition is used to prevent self-assignment
            delete[]p;
            _a = other._a;
            p = new int[other._a];
            std::copy(other.p, other.p + _a, p);
        }
        return *this;
    }

 // --- In move semantics, 'new' should now apper.---
    // move constructor
    Entity(Entity &&other) noexcept : _a(other._a), p(other.p){
        other._a = 0;
        other.p = nullptr;
    }

    // move assignment constructor
    Entity& operator=(Entity &&other){
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
```

```cpp
int main(){
    Entity foo(10);
    
    // call copy constructor
    Entity bar1(foo);
    Entity bar2 = foo;
    
    // call copy assignment constructor
    Entity hi(5);
    hi = foo;

    // call move constructor
    Entity m1(std::move(bar1))
    Entity m2 = std::move(bar2);

    // call move assinment constructor
    Entity n(8);
    n = std::move(10);
}
```

# Rule of zero

Manually managing resources is both tedious and insecure， the wisest approach is to prevent classes from directly managing resources.   
Use standard library components such as `std::string`, `std::vector`, and smart pointers, which internally implement the 3-5 principle.

```cpp
#include<iostream>
#include<memory>
#include<algorithm>

class Entity{
private:
    int _size;
    std::unique_ptr<int[]> data;
public:
    Entity(int s) : _size(s), data(std::make_unique<int[]>(s)){}

    // The following can all be omitted
    ~Entity() = default;
    Entity(Entity&&) = default;
    Entity& operator=(Entity&&) = default;
    
    // Note: std::unique_ptr disables default copying
    // If you still need copying functionality, you need to implement the copying logic manually
    // But usually in resource-intensive development, we only retain move only.
};
```