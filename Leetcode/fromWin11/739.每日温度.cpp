#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

//双指针，但{99，99，99，..., 99, 99, 100}的测试用例会超时
//class Solution {
//public:
//	vector<int> dailyTemperatures(vector<int>& temperatures) {
//		vector<int> answers;
//		int i = 0, j = 0;
//		int interval = 0;
//		while (i < temperatures.size()) {
//			while (temperatures[i] >= temperatures[j] && j < temperatures.size() - 1) {
//				j++;
//			}
//			if (j == temperatures.size() - 1 && temperatures[j] <= temperatures[i]) {
//				interval = 0;
//			}
//			else {
//				interval = j - i;
//			}
//			answers.push_back(interval);
//			j = ++i;
//		}
//		return answers;
//	}
//};

//单调栈
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> answers(temperatures.size());
		stack<int> stk;
		for (int i = 0; i < temperatures.size(); i++) {
			while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
				int m = stk.top();
				answers[m] = i - m;
				stk.pop();
			}
			stk.push(i);
		}
		return answers;
	}
};

int main() {
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
							   //0   1   2   3   4   5   6   7
	Solution sl;
	vector<int> res = sl.dailyTemperatures(temperatures);
	for (auto it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

