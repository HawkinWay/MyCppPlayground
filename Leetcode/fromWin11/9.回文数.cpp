#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//string字符串反转版本
//class Solution {
//public:
//	bool isPalindrome(int x) {
//		if (x < 0)
//			return false;
//		string a = to_string(x);
//		string b = a;
//		reverse(b.begin(), b.end());
//		return a == b;
//	}
//};

//整数计位版本
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		long long rev = 0;
		long long ori = x;
		while (x) {
			int tail = x % 10;
			rev = rev * 10 + tail;
			x = x / 10;
		}
		return ori == rev;
	}
};

int main() {
	Solution sl;
	cout << sl.isPalindrome(21);
	

	return 0;
}