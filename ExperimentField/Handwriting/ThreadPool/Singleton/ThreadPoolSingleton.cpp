#include "../../my_vector/include/my_vector.h"
#include<queue>
#include<functional>
#include<memory>

#include<thread>
#include<mutex>
#include<condition_variable>
#include<future>

#include<iostream>

class ThreadPoolSingleton{
private:
    ThreadPoolSingleton(size_t threadNums){
        for(auto i = 0; i < threadNums; i++){
            _v_threads.emplace_back(std::thread([this](){
                while(1){
                    std::unique_lock<std::mutex> ulk(_mtx);
                    _cond.wait(ulk, [this](){
                        return !_q_tasks.empty() || _stop;
                    });
                    if(_stop && _q_tasks.empty()){
                        return;
                    }
                    std::function<void()> task = std::move(_q_tasks.front());
                    _q_tasks.pop();
                    ulk.unlock();
                    task();
                }
            })
            );
        }
    }
    ThreadPoolSingleton(const ThreadPoolSingleton& other) = delete;
    ThreadPoolSingleton& operator=(const ThreadPoolSingleton& other) = delete;

    public:
    static ThreadPoolSingleton& getInstance(){
        static ThreadPoolSingleton entity{8};
        return entity;
    }

    template<typename Func, typename... Arguments>
    auto enqueue(Func&& func, Arguments&&... args) -> std::future<std::invoke_result_t<Func, Arguments...>>{
        using return_type = std::invoke_result_t<Func, Arguments...>;

        std::shared_ptr<std::packaged_task<return_type()>> task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<Func>(func), std::forward<Arguments>(args)...)
        );

        std::future<return_type> future_result =  task->get_future();
        {
            std::unique_lock<std::mutex> ulk(_mtx);
            _q_tasks.emplace([task](){ (*task)(); });
        }
        _cond.notify_one();

        return future_result;
    }

    ~ThreadPoolSingleton(){
        {
            std::unique_lock<std::mutex> ulk(_mtx);
            _stop = true;
        }
        _cond.notify_all();
        for(auto &thread : _v_threads){
            if(thread.joinable()){
                thread.join();
            }
        }

    }
private:
    Shovy::vector<std::thread> _v_threads;
    std::queue<std::function<void()>> _q_tasks;
    
    std::mutex _mtx;
    std::condition_variable _cond;
    // std::once_flag _once;

    bool _stop = false;
};


int main() {
    // 无需手动创建 ThreadPool 对象，直接通过 getInstance 获取
    auto future = ThreadPoolSingleton::getInstance().enqueue([](int x) {
        return x * x;
    }, 10);

    // 在等待任务完成时，主线程可以继续做其他事
    std::cout << "Calculating..." << std::endl;

    // 获取异步结果
    std::cout << "Result: " << future.get() << std::endl;

    return 0;
}