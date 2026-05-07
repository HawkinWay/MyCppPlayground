#include<iostream>
#include<unordered_map>
#include<vector>

int main(){
    std::vector<int> nums{1,2,3,4,5};
    std::unordered_map<int, int> mp;
    int idx = 0;        
    for(const auto& i : nums){
        mp[idx++] = i;
    }
    for(const auto& i : mp){
        std::cout << "1st: " << i.first << "\t2nd: " << i.second << std::endl;
    }
}

// 哈希表存 数组索引:值 是有序的