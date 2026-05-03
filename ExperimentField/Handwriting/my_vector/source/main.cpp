#include "../include/my_vector.h"
#include<iostream>

template<typename T>
void print(const Shovy::vector<T>& vec){
    std::cout << "\n--------------print\n";
    auto n = vec.size();
    for(auto i = 0; i < n; i++){
        std::cout << "vec[" << i << "]: " << vec[i] << "\n";
    }
}

#define p print(vec)

int main(){
    Shovy::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    p;
    vec.pop_back();
    p;
    vec.clear();
    p;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    //test assert
    std::cout << vec[5]; 

    vec.emplace_back(4);
    p;
}