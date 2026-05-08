// a class template
// wrap a callable object in an asynchronous operation, and return a 'std::future' object

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

int func2(int a, int b){
    return a + b;
}

int main(){
    std::packaged_task<int()> pkg_task(func);
    auto future_result = pkg_task.get_future();

#if 0
    pkg_task();
    func();
#endif
    std::thread t1(std::move(pkg_task));    // here use thread to execute pkg_task()
    std::cout << "func(): " << func() << std::endl;
    t1.join();
    std::cout << "future_result.get(): " << future_result.get() << std::endl;

#if 0
    std::packaged_task<int()> pkg_task2(func2(,1, 2)));     //error, func2(1,2) is a int result, not a callable object
#endif
    std::packaged_task<int()> pkg_task2(std::bind(func2, 1, 2));
    std::future<int> future_result2 = pkg_task2.get_future();
    pkg_task2();
    std::cout << "future_result2.get(): " << future_result2.get() << std::endl;
}