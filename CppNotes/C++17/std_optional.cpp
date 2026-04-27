// a template class
// Before this, we usually used "-1", "0" or "nullptr" to indicate no result
// std::optional uses a type-safe way to indicate a value may exist or not

#include<iostream>
#include<optional>
#include<string>

std::optional<int> findUserID(const std::string& name){
	if(name == "Shovy")
		return 123;
	return std::nullopt;	// explicit no-value
}

int main(){
	auto ID = findUserID("Shovy");
	if(ID.has_value()){
		std::cout << "ID: " << ID.value() << std::endl;
	}
	if(ID){
		std::cout << "ID: " << *ID << std::endl;
	}
	auto ID2 = findUserID("Way").value_or(000);
	std::cout << ID2 << std::endl;
}

