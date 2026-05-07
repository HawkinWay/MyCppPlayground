#include<iostream>
#include<thread>
#include<future>

int func(){
    int i = 0;
    for(i = 0; i < 1000; i++){
        i++;
    }
    return i;
}

int main(){
    std::packaged_task<int()> pkg_task(func);
    auto future_result = pkg_task.get_future();

    std::thread t1(std::move(pkg_task));
    std::cout << "func(): " << func() << std::endl;
    t1.join();
    std::cout << "future_result.get(): " << future_result.get() << std::endl;
}