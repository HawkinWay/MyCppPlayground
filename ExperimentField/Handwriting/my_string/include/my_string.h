#pragma once

#include<iostream>
#include<stdexcept>
#include<cstring>
#include<utility>

namespace Shovy{
class string{
public:
    string(){
        _p = new char[1];
        _p[0] = '\0';
    }

    string(const char* str_p){
        size_t len = (str_p == nullptr) ? 0 : std::strlen(str_p);
        assign(str_p, len);
    }

    string(const string& other){
        assign(other._p, other.m_length);
    }

#if 0
    string& operator=(const string& other){
        if(this == &other){
            return *this;
        }
        delete[]_p;
        assign(other._p, other.m_length);
        return *this;
    }
#endif

    string& operator=(string other){    // notice "string other", this is a temporary copied obj, will be destroyed after the function
        std::swap(_p, other._p);
        std::swap(m_length, other.m_length);
        return *this;
    }

    string(string&& other) noexcept : _p(other._p), m_length(other.m_length){
        other._p = new char[1];
        other._p[0] = '\0';
        other.m_length = 0;
    }

    string& operator=(string&& other) noexcept{
        if(this == &other){
            return *this;
        }
        delete[]_p;
        _p = other._p;
        m_length = other.m_length;

        other._p = new char[1];
        other._p[0] = '\0';
        other.m_length = 0;

        return *this;
    }

    ~string(){
        delete[]_p;
    }


    
    char& operator[](size_t index){
        if(index < m_length)
        return _p[index];
        else
        throw std::out_of_range("string index out of range!");
    }
    
    const char& operator[](size_t index) const{
        if(index < m_length)
        return _p[index];
        else
        throw std::out_of_range("string index out of range!");
    }
    
    

    const char* c_str() const noexcept{
        return _p;
    }

    constexpr size_t size() const{
        return m_length;
    }
    
    constexpr bool empty() const{
        return m_length == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const string& s);

private:
    void assign(const char* str_p, size_t len){
        m_length = len;
        _p = new char[m_length + 1];
        if(m_length > 0 && str_p != nullptr)
            std::memcpy(_p, str_p, m_length);
        _p[m_length] = '\0';
    }

    char* _p = nullptr;
    size_t m_length = 0;
};

std::ostream& operator<<(std::ostream& os, const string& s){
        return os << (s._p ? s._p : "");
}

}
