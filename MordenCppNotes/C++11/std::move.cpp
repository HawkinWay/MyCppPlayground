#include<iostream>
#include<cstring>

class String {
private:
    char* m_Data;
    uint32_t m_Size;
public:
    String() = default;
    String(const char* string) {
        printf("String(const char* string), Created!\n");
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
        printf("String(String&& other), Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Data = nullptr;
        other.m_Size = 0;
    }
 
   ~String() {
        printf("~Sring(), Destroyed!\n");
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
    Entity(String&& name) : m_Name(std::move(name)) {   //调用的是m_Name((String&&)name),将左值转换为右值
            std::cout << "Entity(String&& name).\n";
    }
    void PrintName() {
        m_Name.Print();
    }
};

int main(){
    Entity entity(String("原神"));
    entity.PrintName();
    

    //浅拷贝：直接赋值（⚠️危险，两个指针会指向同一块内存空间）      深拷贝：分配空间后拷贝
    int a = 10;
    int b = a;      // a and b are both lvalue

    int m = 10;
    //int &&n = m;   // wrong
    //int &n = 10;   // wrong
    int &&n = 11;
    n = 100;
    std::cout << "n: " << n << std::endl;
    
    //int &j = 10;  //wrong,左值引用不能绑定右值
    const int &j = 10;  //const左值引用可以绑定右值
                        //这会创建临时对象，相当于  int temp = 10;     const int &j = temp;
    
    std::string s = "hello";
    std::string t = std::move(s);    //std::move()是xvalue，属于右值的一种。移动后s仍然是有效对象 但处于未指定状态（不一定为空）

}