#include <iostream>
#include <mutex>
#include <unordered_map>

// Make variable scope minimum and avoid contaminating outside
// Always used in lock, iterator scenario

int main(){
	std::unordered_map<int, int> mp = { {1, 2}, {3, 4} };

	// make iterator initialize in if() scope
	if(auto it = mp.find(1); it != mp.end()){
		std::cout << it->second;
	} // iterator destroyed when if() end up
	
	std::mutex mtx;
	std::vector<int> pool;
	if(std::lock_guard lk(mtx); !pool.empty()){
		// do something...
	} // lk destroyed when if() end up
}
