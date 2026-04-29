#include<iostream>
#include<string>

template<class T>	// here, class and typename are the same
// or you can write template<typename T>
void print(T foo){
	std::cout << foo << std::endl;
}


template<typename T, int N>
class Array{
private:
	T _Array[N];
public:
	int GetSize() const;
};
// define outside class
template<typename T, int N>
int Array<T, N>::GetSize() const{
	return N;
}

int main(){
	// if you don't call the template function, then it doesn't actually exist
	
	Array<std::string, 5>array;

	std::cin.get();
}
