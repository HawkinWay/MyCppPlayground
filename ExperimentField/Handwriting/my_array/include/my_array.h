#pragma once

#include<cstddef>
#include<stdexcept> 	// For std::out_of_range
#include<initializer_list>
#include<algorithm>

namespace Shovy{
template<typename T, size_t N>
class array{
private:
	T m_data[N];	// Good practice to prefix private members
public:
	array(){
		for(auto& i : m_data){
			i = 0;
		}
	}

	array(std::initializer_list<T> init){
		size_t i = 0;
		for (const auto& val : init) {
        	if (i < N) m_data[i++] = val;
    	}
    	// Fill remaining slots with default values if init is smaller than N
    	while (i < N) m_data[i++] = T{};
	}

	constexpr size_t size() const{
		return N;
	}
	constexpr bool empty() const{
		return N == 0;
	}

	T& at(size_t);
	const T& at (size_t) const;
	/*
	void print_first(const Shovy::array<int, 5>& arr) {
    	// 因为 arr 是 const，编译器会调用第二个版本： const int& at(size_t n) const;
    	std::cout << arr.at(0); 
	}
	*/

	/*
	array& operator[](size_t);	
	this will return entire contianer, 
	we just need some operations like "arr[0] = 10"
	*/
	T& operator[](size_t i){
		return m_data[i];
	}
	const T& operator[](size_t i) const{
		return m_data[i];
	}

	T* begin(){
		return m_data;
	}
	const T* begin() const{
		return m_data;
	}
	T* end(){
		return m_data + N;
	}
	const T* end() const{
		return m_data + N;
	}

	T& front(){
		return m_data[0];
	}
	T& back(){
		return m_data[N - 1];
	}

	void fill(const T&);
};

template<typename T, size_t N>
T& array<T, N>::at(size_t i){
	if(i >= N)
		throw std::out_of_range("Index out of bounds!");
	return m_data[i];
}

template<typename T, size_t N>
const T& array<T, N>::at(size_t i) const {
    if (i >= N) throw std::out_of_range("Index out of bounds!");
    return m_data[i];
}

template<typename T, size_t N>
void array<T, N>::fill(const T& x){
	for(auto& i : m_data){
		i = x;
	}
}

}	// namespace Shovy




