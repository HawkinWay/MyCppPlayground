// A hand-written class that overloads operator() to act like a function object (functor).
#include <iostream>

class Functor {
public:
    explicit Functor(int other_num): m_num(other_num){}

    bool operator()(int other){
        std::cout << "Functor called: ";
        return other > m_num;
    }

private:
    int m_num;
};

int main(){
    Functor func(1);
    std::cout << (func(2) ? "yes" : "no") << '\n';
    std::cout << (func(0) ? "yes" : "no") << '\n';
}