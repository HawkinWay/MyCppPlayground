#include<iostream>
#include<vector>
#include<functional>

void foo(std::function<void(int)> func){
    func(5);
}

int main(){
    auto f = [](int x){std::cout<< x << std::endl;};
    void (*f2)(int) = f;
    std::cout << "foo(f): ";
    foo(f);
    std::cout << "foo(f2): ";
    foo(f2);
    std::cout << std::endl;

    std::vector<std::function<void(int)>> vecfunc;
    // vecfunc.push_back([](){std::cout << "none" << std::endl;});
    // ~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~
    // ERROR: no matching member function for call to 'push_back'
    vecfunc.push_back([](int x){std::cout << x << std::endl;});
    vecfunc.push_back(f);
    vecfunc.push_back([m=8](int x){std::cout << m << std::endl;});
    for(auto i = 0; i < vecfunc.size(); i++){
        std::cout << "vecfunc[" << i << "]: ";
        vecfunc[i](10);
    }


    std::cin.get();
}