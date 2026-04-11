#include<iostream>
#include<cstring>
#include<cstdint>


// 有名字的就是左值，没名字的就是右值

class String {
private:
    char* m_Data;
    uint32_t m_Size;
public:
    String() = default;
    String(const char* string) {
        printf("String(const char* string), Created!\n");   // 1 String("原神"), 产生一个匿名临时对象（右值）,堆上分配了一块内存，存放着“原神”。
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
 
    String(const String& other) {
        printf("String(const String& other), Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    
    String(String&& other) {
        printf("String(String&& other), Moved!\n");     // 2 临时对象被作为参数传递给 name
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Data = nullptr;
        other.m_Size = 0;
    }
 
   ~String() {
        printf("~Sring(), Destroyed!\n");       // 4 那个匿名的临时对象（原本叫 name 的那个）生命周期结束了    6 对象 entity 被销毁
        delete[] m_Data;
    }
 
    void Print() {
        for (uint32_t i = 0; i < m_Size; ++i)
            printf("%c", m_Data[i]);
 
        printf("\n");
    }
};
 
class Entity {
private:
    String m_Name;
public:
    Entity(const String& name) : m_Name(name) {
            std::cout << "Entity(const String& name).\n";
    }
    // Entity(String&& name) : m_Name((String&&)name) {
    //         std::cout << "Entity(String&& name).\n";
    // }
    Entity(String&& name) : m_Name(std::move(name)) {   // 3 调用的是m_Name((String&&)name),将左值转换为右值
            std::cout << "Entity(String&& name).\n";    // 这里虽然类型是右值引用，但因为它有名字 name ，它在语法上被视为左值，直接m_Name(name)依然会调用拷贝构造函数（深拷贝）。
    }                                                   // 加上 std::move(name) 后，它被转换回右值，触发 String(String&& other)。
            
    void PrintName() {
        m_Name.Print();     // 5
    }
};

int main(){
    Entity entity(String("原神"));  // 1 2 3 4
    entity.PrintName();     // 5
    

    //浅拷贝：直接赋值（⚠️危险，两个指针会指向同一块内存空间）      深拷贝：分配空间后拷贝
    int a = 10;
    int b = a;      // a and b are both lvalue

    int m = 10;
    //int &&n = m;   // wrong, rvalue reference can't be bound to lvalue
    //int &n = 10;   // wrong, lvalue reference can't be bound to rvalue
    int &&n = 11;
    n = 100;
    std::cout << "\nn: " << n << std::endl;
    
    //int &j = 10;      //wrong,左值引用不能绑定右值
    const int &j = 10;  //const左值引用可以绑定右值
                        //这会创建临时对象，相当于  int temp = 10;     const int &j = temp;
    
    std::string s = "hello";
    std::string b = s;      // 拷贝：b 申请了新内存，复制了 s 的内容
    std::string t = std::move(s);    // t 直接接管 s 的原本拥有的资源(如堆内存指针)，s 变为有效但未指定的状态
    
    //std::move()是xvalue，属于右值的一种。移动后s仍然是有效对象 但处于未指定状态（不一定为空）
}