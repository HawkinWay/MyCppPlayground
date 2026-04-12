#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int head = 0, tail = 0;
        int n = nums.size();
        while (tail < nums.size()) {
            if (nums[tail] != 0) {
                nums[head] = nums[tail];
                head++;
            }
            tail++;
        }
        while (head < nums.size()) {
            nums[head] = 0;
            head++;
        }
    }
};

int main() {
    vector<int> arr = { 0,1,0,3,12 };
    Solution sl;
    sl.moveZeroes(arr);
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}