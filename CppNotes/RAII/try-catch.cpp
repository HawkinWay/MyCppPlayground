#include<iostream>

void newdel(){
            int *my_int = new int[10];
            std::cout << "创建 int *my_int = new int[10];" << std::endl;

            throw std::runtime_error("异常");       // 在try块中抛出异常后，throw的后续内容不会继续进行

            delete[]my_int;
            std::cout << "内存已释放！" << std::endl;
        }

int main(){
    try{
        newdel();
    }
    catch(const std::exception &e){
        std::cout << "捕获异常！" << std::endl;
    }
}