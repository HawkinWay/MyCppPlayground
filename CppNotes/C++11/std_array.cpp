#include<iostream>
#include<array>
#include<functional>

// std::array 强制类型检查，避免了 C 语言数组的类型不安全问题。
// 数组的大小在编译时确定，不能在运行时改变。
// std::array 的元素在内存中是连续存储的(存储在栈上)，这使得它可以高效地访问元素。
// std::array 提供了与 std::vector 类似的接口，如 size(), at(), front(), back() 等。

// std::array<type, value> 第一个参数为类型，第二个参数为值

template<typename T, size_t N>
void printArray(const std::array<T, N>& arr){
	for(auto i = 0; i < arr.size(); i++){
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
	}
}

int main() {
	std::array<int, 5> nums = { 1,2,3,4,5 };
	std::cout << "nums: ";
	for(auto &i : nums){
		std::cout << i << " ";
	}

	std::cout << "\nprintArray(nums): " <<std::endl;
	printArray(nums);
	
	std::cin.get();
}