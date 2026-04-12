#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {
		unordered_map<char, string> map;
		unordered_map<string, char> used;
		vector<string> vs;
		int j = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				vs.push_back(s.substr(j, i - j));
				j = i + 1;
			}
		}
		vs.push_back(s.substr(j, s.size() - j));
		if (vs.size() != pattern.size())
			return false;
		for (int i = 0; i < vs.size(); i++) {
			if (map.find(pattern[i]) == map.end()) {
				if (used.find(vs[i]) != used.end())
					return false;
				map[pattern[i]] = vs[i];
				used[vs[i]] = pattern[i];
			}
			else {
				if (map[pattern[i]] != vs[i])
					return false;
			}
		}
		
		return true;
	}
};

int main() {
	string pattern = "abba";
	string s = "dog cat cat dog";
	Solution sl;
	if (sl.wordPattern(pattern, s) == true)
		cout << "true." << endl;
	else
		cout << "false." << endl;

	return 0;
}