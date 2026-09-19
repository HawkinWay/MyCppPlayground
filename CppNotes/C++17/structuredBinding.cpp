#include <iostream>
#include <map>
#include <string>

int main(){
	std::pair<int, std::string> p{1, "a"};
	auto [id, name] = p;	// copy
	auto& [rid, rname] = p;	// reference

	std::map<int, std::string> mp;
	for(const auto& [i, s] : mp)
		std::cout << "i: " << i << ", s: " << s << '\n';
}
