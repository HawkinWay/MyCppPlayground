#include<iostream>
#include<string>
#include<thread>
#include<mutex>

class LOG{
private:
    LOG(){}
    LOG(const LOG& log) = delete;
    LOG& operator=(const LOG& log) = delete;    
public:
    static LOG& getInstance(){
        std::call_once(_once, init);
        return *_log;
    }

    void printLOG(std::string msg){
        std::lock_guard<std::mutex> lg(_mtx);
        std::cout << __TIME__ << " " << msg << std::endl;
    }
private:
    static void init(){
        if(!_log)
            _log = new LOG{};
    }

    static std::once_flag _once;    // prevent two threads call printLOG at the same time
    static LOG* _log;
    std::mutex _mtx;
};

LOG* LOG::_log = nullptr;
std::once_flag LOG::_once;

void print(int id){
    LOG::getInstance().printLOG("call print(" + std::to_string(id) + ")");
}

int main(){
    // LOG{}.getInstance().printLOG("Hello world!");
    LOG::getInstance().printLOG("Hello world!");
    std::thread t1(print, 1);
    std::thread t2(print, 2);
    t1.join();
    t2.join();
}