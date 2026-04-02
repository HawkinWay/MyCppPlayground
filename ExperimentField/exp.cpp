#include<iostream>
#include<vector>
#include<memory>
#include<unordered_map>

class ptr_exp{
public:
    ptr_exp(int n){
        n = 369;
    }
    
    void releaseHere(){

    }

};

int main(){
    std::vector<char> s = {'W','h','a','t'};
    std::cout << "s[0]: " << s[0] << std::endl;     //s[0]: W
    std::vector<char> s0(26);
    std::cout << "itVec: " << std::endl;
    for(std::vector<char>::iterator itVec = s0.begin(); itVec<s0.end(); itVec++){
        std::cout << *itVec << " "; 
    }
    std::cout << std::endl;

    char b = 'b';
    std::cout << "char b: " << b << std::endl;
    std::cout << "char b - 0: " << b - 0 << std::endl;
    std::cout << "char b - 1: " << b - 1 << std::endl;
    std::cout << "char b - 'a': " << b - 'a' << std::endl;
    std::cout << "char b - 97: " << b - 97 << std::endl;
    std::cout << "char b - 97: " << b - 97 << std::endl; 



    std::unique_ptr<int> uit = std::make_unique<int>(5);
    std::unique_ptr<int> lit;
    auto it = *uit;
    auto &it2 = *uit;
    std::cout << "\n*uit: " << *uit << "\nit = *uit: " << it << "\n&it2 = *uit: " << it2 << std::endl;

    std::unique_ptr<ptr_exp> it_ptr_exp = std::make_unique<ptr_exp>(48);
    std::cout << "*it_ptr_exp: " << it_ptr_exp.release();

    std::unordered_map<int, int> mp;
    for(auto& i : mp){
        i.second = 0;
    }
    uint i = mp.size();
    auto k = static_cast<int>(i);
}