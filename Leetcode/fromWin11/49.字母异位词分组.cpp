#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//ÅÅÐò+¹þÏ£  O(nklog k)
//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		unordered_map<string, vector<string>> map;
//		for (auto i : strs) {
//			string s = i;
//			sort(i.begin(), i.end());
//			map[i].push_back(s);
//		}
//		vector<vector<string>> res;
//		for (auto& pr : map) {
//			res.push_back(pr.second);
//		}
//		return res;
//	}
//};

//¼ÆÊý·¨	O(nk)
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map;
		for (auto& i : strs) {
			vector<int> cnt(26, 0);
			for (auto& j : i) {
				cnt[j - 'a']++;
			}
			string key;
			for (int i = 0; i < 26; i++) {
				key += to_string(cnt[i]) + "#";
			}
			map[key].push_back(i);
		}
		vector<vector<string>> res;
		for (auto& i : map) {
			res.push_back(i.second);
		}
		return res;
	}
};

int main() {
	vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
	/*for (auto& it : strs) {
		cout << it << " ";
	}*/
	Solution sl;
	auto it = sl.groupAnagrams(strs);

	for (auto i : it) {
		cout << "[";
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "] ";
	}
	
	
}