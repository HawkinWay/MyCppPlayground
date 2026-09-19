#include <iostream>
#include <string>

// A read-only view of string, with no memory allocation and cheap overhead
// Do not guarantee end with '\0'

void func(std::string_view sv);		// can accept string, const char*, literal

std::string_view bad(){
	std::string s = "temp";
	return s;	// danger, dangling
}

int main(){
	std::string s = "hello";
	std::string_view sv = s;	// without copying
	sv.substr(1, 3);		// still view, without allocation
}
