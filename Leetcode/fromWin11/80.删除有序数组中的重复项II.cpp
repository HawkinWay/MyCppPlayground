#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int head = 2, tail = 2;
        while (tail < nums.size()) {
            if (nums[tail] != nums[head - 2]) {
                nums[head++] = nums[tail];
            }
            tail++;
        }
        return head;
    }
};

int main() {
    Solution sl;
    vector<int> arr = { 0,1,2,2,2,2,2,3,4,4,4 };
    cout << "after remove, the length is :" << sl.removeDuplicates(arr);

    return 0;
}