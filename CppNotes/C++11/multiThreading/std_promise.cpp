// create a value in a thread, and get the value in another thread

#include<iostream>
#include<thread>
#include<future>

void func(std::promise<int> &f){
    f.set_value(1000);
}

int main(){
    std::promise<int> f;
    auto future_result = f.get_future();

    std::thread t1(func, std::ref(f));
    t1.join();
    
    std::cout << "future_result.get(): " << future_result.get() << std::endl;
}