#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int head = 0, tail = 0;
        while (tail < nums.size()) {
            if (nums[tail] != val) {
                nums[head++] = nums[tail];
              //nums[head] = nums[tail];
              //head++;  
            }
            tail++;
        }

        return head;
    }
};

int main() {
    Solution sl;
    vector<int> arr = { 0,1,2,2,3,0,4,2 };
    cout << "after remove, the length is :" << sl.removeElement(arr,2);

    return 0;
}