#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

//哈希表
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//sort(nums.begin(), nums.end());			//不是sort(nums.begin(), nums.end() - 1);，因为左闭右开[begin,end)

		unordered_set<int> st;
		for (auto& i : nums) {
			st.insert(i);
		}
		int cur = 0, len = 0, mxlen = 0;
		for (auto& m : st) {
			if (st.find(m - 1) == st.end()) {
				cur = m;
				len = 1;
				while (st.find(cur + 1) != st.end()) {
					cur++;
					len++;
				}
				if (len > mxlen) {
					mxlen = len;
				}
			}
		}
		return mxlen;
	}
};

int main() {
	vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };
	Solution sl;
	cout << "the continuous length is :" << sl.longestConsecutive(nums);

	return 0;
}

