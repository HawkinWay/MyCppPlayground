#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//Ò»ÐÐÃë
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        reverse(s.begin(), s.end());
//    }
//};

//Ë«Ö¸Õë
class Solution {
public:
    void reverseString(vector<char>& s) {
        auto p1 = s.begin();
        auto p2 = s.end() - 1;
        while (p1 != p2) {
            swap(*p1, *p2);
            p1++;
            p2--;
        }
    }
};

int main() {
    vector<char> arr1 = { 'h','e','l','l','o' };
      
    Solution sl;
    sl.reverseString(arr1);
    vector<char>::iterator it1;
    for (it1 = arr1.begin(); it1 != arr1.end(); it1++) {
        cout << *it1;
    }
    cout << endl;
    
    return 0;
}

