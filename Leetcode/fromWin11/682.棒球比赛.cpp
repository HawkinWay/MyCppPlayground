#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

//栈
//class Solution {
//public:
//	int calPoints(vector<string>& operations) {
//		vector<string> res;
//		for (auto& i : operations) {
//			if (i == "C") {
//				res.pop_back();
//			}
//			else if (i == "D") {
//				int bk = stoi(res.back());
//				bk *= 2;
//				res.push_back(to_string(bk));
//			}
//			else if (i == "+") {
//				int pl = stoi(res.back()) + stoi(*(res.end() - 2));			//stoi(*(res.end() - 2)也可以写成stoi(res[res.size() - 2])
//				res.push_back(to_string(pl));
//			}
//			else {
//				res.push_back(i);
//			}
//		}
//		int count = 0;
//		for (auto& i : res) {
//			count += stoi(i);
//		}
//		return count;
//	}
//};

//方法同上，但不绕
class Solution {
public:
	int calPoints(vector<string>& operations) {
		vector<int> res;
		for (auto& i : operations) {
			if (i == "C") {
				res.pop_back();
			}
			else if (i == "D") {
				res.push_back(res.back() * 2);
			}
			else if (i == "+") {
				res.push_back(res[res.size() - 1] + res[res.size() - 2]);
			}
			else {
				res.push_back(stoi(i));
			}
		}
		int count = 0;
		for (auto& i : res) {
			count += i;
		}
		return count;
	}
};

int main() {
	vector<string> op = { "5","-2","4","C","D","9","+","+" };
	
	Solution sl;
	cout << sl.calPoints(op);

	return 0;
}

