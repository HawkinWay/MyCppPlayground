#include<vector>
#include<queue>

#include<thread>
#include<mutex>
#include<condition_variable>
#include<functional>

#include<iostream>
#include<stdio.h>

class ThreadPool{
public:
    ThreadPool(int threadNums) : _stop(false) {
        for(auto i = 0; i < threadNums; i++){
            _v_threads.emplace_back([this](){
                while(1){
                    std::unique_lock<std::mutex> ulc(_mtx);
                    _cond.wait(ulc, [this](){
                        return !_q_tasks.empty() || _stop;
                    });
                    if(_stop && _q_tasks.empty())
                        return;
                    
                    auto task = std::move(_q_tasks.front());
                    _q_tasks.pop();
                    //ulc.unlock();
                    task();
                }
            });
        }
    }

    ~ThreadPool(){
        {
            std::unique_lock<std::mutex> ulc(_mtx);
            _stop = true;
        }
        _cond.notify_all();
        for(auto& i : _v_threads){
            i.join();
        }
    }

    template<typename T, typename... Arguments>
    void enqueue(T&& t, Arguments&&... args){
        std::function<void()> task = std::bind(std::forward<T>(t), std::forward<Arguments>(args)...);
        {
            std::unique_lock<std::mutex> ulc(_mtx);
            _q_tasks.emplace(std::move(task));
        }
        _cond.notify_one();
    }

private:
    std::vector<std::thread> _v_threads;
    std::queue<std::function<void()>> _q_tasks;

    std::mutex _mtx;
    std::condition_variable _cond;

    bool _stop;
};

int main(){
    ThreadPool tp(4);
    for(auto i = 0; i < 10; i++){
        tp.enqueue([i](){ 
            // std::cout << "task: " << i << " is running..." << std::endl; 
            printf("task: %d is running...\n", i);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // std::cout << "task: " << i << " has finished." << std::endl;
            printf("task: %d has finished.\n", i);
        });
    }
}