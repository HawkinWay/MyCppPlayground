#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		unordered_map<char, char> map;
		unordered_map<char, char> used;
		for (int i = 0; i < s.size(); i++) {
			if (map.find(s[i]) == map.end()) {
				if (used.find(t[i]) != used.end()) {
					if (used[t[i]] != s[i]) {
						return false;
					}
				}
				map[s[i]] = t[i];
				used[t[i]] = s[i];
			}
			else {
				if (map[s[i]] != t[i])
					return false;
			}
		}
		
		return true;
	}
};

int main() {
	string s = "add";
	string t = "cbb";
	Solution sl;
	if (sl.isIsomorphic(s, t) == true)
		cout << "true." << endl;
	else
		cout << "false." << endl;

	return 0;
}