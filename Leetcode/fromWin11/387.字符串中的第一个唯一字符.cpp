#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

//哈希表
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		unordered_map<char, int> map;
//		for (auto& i : s) {
//			map[i]++;
//		}
//		for (int i = 0; i < s.size(); i++) {
//			if (map[s[i]] == 1) {
//				return i;
//			}
//		}
//		return -1;
//	}
//};

//哈希表数组
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> vec(26, 0);
		/*原错误代码，i取vec中元素，全为0
		for (auto& i : vec) {
			vec[s[i] - 'a']++;
		}*/
		for (auto& i : s) {
			vec[i - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (vec[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}
};


int main() {
	string s = "loveleetcode";
	Solution sl;
	cout << "the first unique char is :" << sl.firstUniqChar(s) << endl;

	return 0;
}