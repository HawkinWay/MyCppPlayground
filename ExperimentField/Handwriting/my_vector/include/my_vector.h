#pragma once

#include<cstddef>
#include<initializer_list>
#include<algorithm>
#include<cstddef>
#include<cassert>
#include<new>

namespace Shovy{
template<typename T>
class vector{
private:
	T* m_data = nullptr;
	size_t m_eleNums = 0;	// elements actually inside vector
	size_t m_capacity = 0;	// memories we allocated
public:
	vector(){
		ReAlloc(2);	
	}

	vector(const vector&) = delete;
	vector& operator=(const vector&) = delete;

	~vector(){
		// delete[]m_data;
		clear();
		::operator delete(m_data, m_capacity * sizeof(T));

	}

	void push_back(const T& value){		// although const T& value can accept both lvalue and rvalue, it's const. std::move() needs modify value to rvalue
		if(m_eleNums >= m_capacity){
			ReAlloc(m_capacity + m_capacity / 2);
		}
		m_data[m_eleNums] = value;
		m_eleNums++;
	}

	void push_back(T&& value){
		if(m_eleNums >= m_capacity){
			ReAlloc(m_capacity + m_capacity / 2);
		}
		m_data[m_eleNums] = std::move(value);
		m_eleNums++;
	}

	void pop_back(){
		if(m_eleNums > 0){
			m_eleNums--;
			m_data[m_eleNums].~T();
		}
	}

	template<typename... Arguments>
	T& emplace_back(Arguments&&... args){
		if(m_eleNums >= m_capacity){
			ReAlloc(m_capacity + m_capacity / 2);
		}
		#if 0
		// Perfect Forwarding: if the raw attribute of arg is an rvalue, std::forward converts it back to an rvalue.
		//					   if the raw attribute of arg is an lvalue, std::forward converts it back to an lvalue.
		m_data[m_eleNums] = T(std::forward<Arguments>(args)...);	// ... acts on std::forward<Arguments>(args)
						//  T(std::forward<Arguments>(args...));	// ... acts on args, std::forward will recieve a large number of args, but it can only handle one arg at a time
		#endif
		T* elementPtr = new (&m_data[m_eleNums]) T(std::forward<Arguments>(args)...);
		m_eleNums++;
		return *elementPtr;
	}

	void clear(){
		for(auto i = 0; i < m_eleNums; i++){
			m_data[i].~T();		// Explicit Destructor Call，That memory still belongs to your program， it's just that the internal resources of the object are being released.
		}
		m_eleNums = 0;
	}

	size_t size() const{
		return m_eleNums;
	}
	
	T& operator[](size_t i){
		return m_data[i];
	} 

	const T& operator[](size_t i) const{
		// static_assert(i <= m_capacity, "out of range!");		'i' is run-time constant, static_assert needs compile-time constant
		assert(i < m_eleNums && "out of range!");	// if true, program goes on. if not, program crashed
		return m_data[i]; 
	}

	T* begin(){
		return m_data;
	}

	const T* begin() const{
		return m_data;
	}

	T* end(){
		return m_data + m_eleNums;
	}

	const T* end() const{
		return m_data + m_eleNums;
	}


private:
	void ReAlloc(size_t newCapacity){
		// 1. allocate a new block of memory
		// T* newBlock = new T[newCapacity];	this will immediately call the newCapacity second-default constructor, cost a huge overhead
		T* newBlock = static_cast<T*>(::operator new(newCapacity * sizeof(T)));	// ::operator new allocates bytes
		if(newCapacity < m_eleNums){
			m_eleNums = newCapacity;
		}
		
		// 2. copy/move old elements into new block
		// newBlock = std::move(m_data);	error, 1. If you "move" the pointer, you are just copying a 64-bit address. 2. The objects sitting at that address are still sitting there.
		// for(auto i = 0; i < m_eleNums; i++){
		// 	newBlock[i] = std::move(m_data[i]);
		// }
		for(auto i = 0; i < m_eleNums; i++){
			new (newBlock + i) T(std::move(m_data[i]));
		}

		for(auto i = 0; i < m_eleNums; i++){
			m_data[i].~T();	
		}
		
		// 3. delete
		// delete[]m_data;
		::operator delete(m_data, m_capacity * sizeof(T));
		m_data = newBlock;
		m_capacity = newCapacity;
	}
};
}   // namespace Shovy
