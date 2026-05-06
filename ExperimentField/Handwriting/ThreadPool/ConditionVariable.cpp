#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<string>
#include<queue>

std::queue<int> _q;
std::condition_variable _cond;
std::mutex _mtx;

void Producer(){
    for(auto i = 1; i <= 10; i++){
        {
            std::unique_lock<std::mutex> ul(_mtx);
            _q.push(i);
            _cond.notify_one();
            std::cout << "Producer: " << i << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Consumer(){
    while(1){
        std::unique_lock<std::mutex> ul(_mtx);
        _cond.wait(ul, [](){ return !_q.empty(); });
#if 0
        while (_q.empty()) {
           _cond.wait(ul);
        }
#endif
        auto value = _q.front();
        _q.pop();
        std::cout << "Consumer: " << value << "\n";
    }
}

int main(){
    std::thread prod(Producer);
    std::thread cons(Consumer);
    prod.join();
    cons.join();
}