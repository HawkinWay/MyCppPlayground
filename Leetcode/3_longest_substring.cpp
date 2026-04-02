#include<iostream>
#include<unordered_map>
#include<string>

class Solution{
public:
    int lengthOfLongestSubstring(std::string s){
        std::unordered_map<char, int> mp;
        int len = 0, maxLen = 0;
        int head = 0;
        for(auto tail = 0; tail < s.size(); tail++){
            mp[s[tail]]++;
            while(mp[s[tail]] > 1){
                mp[s[head++]]--;
            }
            len = tail - head + 1;
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};

int main(){
    std::string s1 = "aab";     //output should be: 2
    std::string s2 = " ";       //output should be: 1
    std::string s3 = "au";      //output should be: 2
    std::string s4 = "pwwkew";  //output should be: 3
    Solution sl;
    std::cout << "output: ";
    std::cout << sl.lengthOfLongestSubstring(s1) << 
        '\n' << sl.lengthOfLongestSubstring(s2) << 
        '\n' << sl.lengthOfLongestSubstring(s3) <<
        '\n' << sl.lengthOfLongestSubstring(s4) << std::endl;
}