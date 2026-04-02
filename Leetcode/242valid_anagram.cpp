#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size())
            return false;
        std::vector<int> apb(26);
        // for(int i = 0; i < s.size(); i++){
        //     apb[s[i] - 'a']++;
        //     apb[t[i] - 'a']--;
        // }
        // for(auto i = 0; i < apb.size(); i++){
        //     if(i != 0)
        //         return false;
        // }
        for(auto &i : s){
            apb[i - 97]++;
        }
        for(auto &i : t){
            apb[i - 'a']--;
            if(apb[i - 'a'] < 0)
                return false;
        }
        return true;
        
    }
};

int main(){
    std::string s = "anagram";
    std::string t = "nagaram";

    Solution sl;
    std::cout << sl.isAnagram(s,t);     // 1

}