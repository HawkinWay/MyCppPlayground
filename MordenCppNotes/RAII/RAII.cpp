#include<iostream>

// RAII核心思想
// 为了防止像"try-catch.cpp"中的内存泄漏，可以把资源的初始化和释放（生命周期）的管理绑定到一个对象obj上
// 对象obj构造函数执行时，自动获取资源； 对象obj析构函数执行时，自动释放资源
// 这样，我们无需手动释放资源，即使程序异常退出或提前返回，也能确保资源得到正确回收。

class RAIImemory{
private:
    int *data;
public:
    explicit RAIImemory(int size) : data(new int[size]){
        std::cout << "RAIImemory构造函数启用, 内存已分配" << std::endl;
    }
    
    ~RAIImemory(){
        delete[]data;
        std::cout << "RAIImemory析构函数启用, 内存已释放" << std::endl;
    }

    int *get(){
        return data;
    }
};

void test(){
    std::cout << "调用test()"  << std::endl;
    RAIImemory testRAII(10);
    
    // 即使发生异常，也会通过栈回退机制，正确释放资源
    // *栈回退机制：发生异常时，调用所有异常前局部变量的析构函数
    throw std::runtime_error("test()异常！");
}

int main(){
    try{
        std::cout << "进入try块" << std::endl;
        test();
    }
    catch(const std::exception &e){
        std::cout << "捕获异常: " << e.what() << std::endl;
    }
}