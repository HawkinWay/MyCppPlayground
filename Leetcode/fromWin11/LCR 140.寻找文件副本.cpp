#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

//¹þÏ£±í
class Solution {
public:
	int findRepeatDocument(vector<int>& documents) {
		unordered_map<int, int> mp;
		
		for (auto& i : documents) {
			mp[i]++;
			if (mp[i] > 1) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> documents = { 2,5,3,0,5,0 };
	
	Solution sl;
	cout << sl.findRepeatDocument(documents) << endl;

	return 0;
}

