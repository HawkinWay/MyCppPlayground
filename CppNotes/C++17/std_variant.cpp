// Unions conserve memory by enabling membes of different types to occupy the same memory location. But they aren't type-safe and are prone to programming errors.
// To solve this issue, C++17 introduces std::variant class.
// The std::visit function can be used to access the members of a variant type in a type-safe manner.
// .index()

// non-member functions
// std::get_if<>()
// std::get<>()

#include<iostream>
#include<variant>
#include<string>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main(){
	std::variant<int, std::string> vj;
	vj = 123;
	vj = "Shovy";
	try{
		std::string s = std::get<std::string>(vj);
		std::cout << s << std::endl;
	}
	catch(const std::bad_variant_access& e){
		// if u try to get non-existent type, will throw exception
	}
	
	std::variant<int, std::string, bool> v = "Shovy";
	

	std::visit(overloaded {
    		[](int arg) { std::cout << "是个整数: " << arg << std::endl; },
    		[](const std::string& arg) { std::cout << "是个字符串: " << arg << std::endl; },
    		[](bool arg) { std::cout << "是个布尔值: " << (arg ? "真" : "假") << std::endl; }
	}, v);

	
	std::variant<int, float, std::string> data = 3.14f;
	std::visit([](auto&& arg){std::cout << "Value:" << arg << std::endl;}, data);

	
	std::variant<int, short> D;
	D = 2;
	std::cout << "D.index(): " << D.index() << std::endl;
	if(auto attempt = std::get_if<float>(&data)){
		std::cout << "find float here." << std::endl;
	}
	std::cout << "std::get<int>(D): " << std::get<int>(D) << std::endl;
}

