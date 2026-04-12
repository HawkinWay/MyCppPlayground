#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

//栈
class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> stk;
		for (auto& i : s) {
			if (stk.empty()) {
				stk.push(i);
			}
			else {
				if (i == stk.top()) {
					stk.pop();
				}
				else {
					stk.push(i);
				}
			}
		}
		string n = "";
		/*for (auto& k : stk) {				**原错误代码：栈无法遍历！
			n += k;
		}*/
		while (!stk.empty()) {
			n += stk.top();					//n = stk.top() + n; 则后续无需反转
			stk.pop();
		}
		reverse(n.begin(), n.end());
		return n;
	}
};

int main() {
	string s = "abbaca";
	
	Solution sl;
	cout << sl.removeDuplicates(s);

	return 0;
}

