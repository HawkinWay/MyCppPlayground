
// variadic function class
// syntax
// template<typename... args> class classname;
// template<typename ... args> class classname;
// template<typename ...args> class classname;

#include<vector>
#include<iostream>

#if 0
template<typename... args> class vtclass;

vtclass<> vtinst1;
vtclass<int> vtinst2;
vtclass<int, float> vtinst3;
vtclass<double, std::vector<int>, float> vtinst4;

// reqiured at least one type when defining
template<typename First, typename... Rest> class classname;


// variadic function template 
// syntax
// template<typename... args> returntype functionname(args... a);
// template<typename... args> returntype functionname(args&... a);
// template<typename... args> returntype functionname(args&&... a);
// template<typename... args> returntype functionname(args*... a);
// template<typename... args> returntype functionname(const args&... a);

template<typename... Arguments>
void tfunc(const Arguments&... args){
	constexpr auto numargs{ sizeof...(Aruguments) };
	X xobj[numargs];   // array of some previously defined type X
	helper_func(xobj, args...);
}
#endif

void print(){
	std::cout << "\n";
}

template<typename T>
void print(const T& t){
	std::cout << t << std::endl;
}

template<typename First, typename... Rest>
void print(const First& first, const Rest&... rest){
	std::cout << "recurse flag: " << first << ", ";
	print(rest...);	// recursive call using pack expansion syntax
}

int main(){
    std::cout << "----------print()\n"; 
	print();
    std::cout << "----------print(const T& t)\n"; 
	print(1);

    std::cout << "----------print(const First& first, const Rest&... rest)\n";
	print(10,20);   // cout flag 10, print(20) ; cout 20
	print(100, 200, 300);   // cout flag 100, print({200, 300}) ; cout flag 200, print(300) ; cout 300
	print("first", 2, "third", 3.14159);    // cout flag first, print({2, "third", 3.14159}) ; cout flag 2, print({"third", 3.14159}) ; cout flag third, print(3.14159) ; cout 3.14159
}
