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
	bool isValid(string s) {
		stack<char> stk;
		for (auto& i : s) {
			if (i == '(' || i == '[' || i == '{') {
				stk.push(i);
			}
			else {
				if (stk.empty())
					return false;
				if (i == ')' && stk.top() != '(')
					return false;
				if (i == ']' && stk.top() != '[')
					return false;
				if (i == '}' && stk.top() != '{')
					return false;
				stk.pop();
			}
		}
		return stk.empty();
	}
};

int main() {

	return 0;
}

