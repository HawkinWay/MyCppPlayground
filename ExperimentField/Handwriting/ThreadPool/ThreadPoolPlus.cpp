#include "../my_vector/include/my_vector.h"
#include<queue>
#include<functional>
#include<memory>

#include<thread>
#include<mutex>
#include<condition_variable>
#include<future>

#include<iostream>

class ThreadPoolPlus{
public:
    ThreadPoolPlus(size_t threadNums) : _stop(false){
        for(auto i = 0; i < threadNums; i++){
            _v_threads.emplace_back([this](){
                while(1){
                    std::unique_lock<std::mutex> ulk(_mtx);
                    _cond.wait(ulk, [this](){
                        return !_q_tasks.empty() || _stop;
                    });
                    if(_stop && _q_tasks.empty()){
                        return;
                    }
                    auto task = std::move(_q_tasks.front());       // better use move
                    _q_tasks.pop();
                    ulk.unlock();
                    task();
                }
            });
        }
    } 

    ~ThreadPoolPlus(){
        {
            std::unique_lock<std::mutex> ulk(_mtx);
            _stop = true;
        }
        _cond.notify_all();
        for(auto &thread : _v_threads){
            if(thread.joinable())
                thread.join();
        }
    }

    template<typename Func, typename... Arguments>
    auto enqueue(Func&& func, Arguments&&... args) -> std::future<std::invoke_result_t<Func, Arguments...>>{
        using return_type = std::invoke_result_t<Func, Arguments...>;
        
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<Func>(func), std::forward<Arguments>(args)...)
        );
        /*std::future<return_type>*/ auto f = task->get_future();
        {
            std::unique_lock<std::mutex> ulk(_mtx);
            _q_tasks.emplace([task](){
                (*task)();
            });
        }
        _cond.notify_one();
        
        return f;
    }
private:
    Shovy::vector<std::thread> _v_threads;
    std::queue<std::function<void()>> _q_tasks;

    std::mutex _mtx;
    std::condition_variable _cond;

    bool _stop;
};

std::mutex cout_mtx;

int adder(int a, int b){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::unique_lock<std::mutex> ulc(cout_mtx);
        std::cout << "add running in thread: " << std::this_thread::get_id() << std::endl;
    }
    return a + b;
}

int main(){
    ThreadPoolPlus pool(5);
    
    Shovy::vector<std::future<int>>  res;

    for(auto i = 0; i < 8; i++){
        res.emplace_back(pool.enqueue(adder, i, i * 2));
    }

    std::cout << "main thread continues..." << std::endl;

    for(auto &r : res){
        std::cout << "r.get(): " << r.get() << std::endl;
    }

    std::cout << "all tasks finished" << std::endl;
}