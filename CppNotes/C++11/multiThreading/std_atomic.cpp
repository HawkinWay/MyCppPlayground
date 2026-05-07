#include<iostream>
#include<vector>
#include<thread>
#include<atomic>

// typically, only primitive types (int, bool, pointer) natively support hardware atomicity.

std::atomic<int> atm(0);    // atomic variables, have built-in locking mechanisms, ensuring the operation is atomic.

void func(){
    for(int i = 0; i < 1000; i++){
        atm++;      // don't need mtx lock
    }
}

int main(){
    std::vector<std::thread> vect;
    
    for(int i = 0; i < 5; i++){
        //vect.emplace_back(std::thread(func));
        vect.emplace_back(func);
    }
    
    for(auto &i : vect){
        if(i.joinable()){   // good practice before join
            i.join();
        }
    }
    
    std::cout << "atm: " << atm.load() << std::endl; 

    atm.store(1);

    std::cout << "atm: " << atm.load() << std::endl; 
}