#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

////排序
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        if (s.size() != t.size())
//            return false;
//        sort(s.begin(), s.end());   //string类不是迭代器，不需要s.end()-1
//        sort(t.begin(), t.end());
//        return s == t;
//    }
//};

////哈希表
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        if (s.size() != t.size())
//            return false;
//
//        unordered_map<char, int> map;
//        for (auto i : s) {
//            map[i]++;
//        }
//        for (auto i : t) {
//            map[i]--;
//        }
//        for (const auto& pair : map) {
//            if (pair.second != 0) {
//                return false;
//            }
//        }
//        return true;
//    }
//};

//哈希表之26个英文字母(无unordered_map)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> num(26, 0);             //26个0
        for (auto i : s) {
            num[i - 'a']++;
        }
        for (auto i : t) {
            num[i - 'a']--;
            if (num[i - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    string s = "ab";
    string t = "ba";
    Solution sl;
    cout << sl.isAnagram(s, t);
    
    return 0;
}

