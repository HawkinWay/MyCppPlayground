#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        int head = 0, tail = 1;
//        while (tail < nums.size()) {
//            if (nums[head] != nums[tail]) {
//                head++;                      //*此处head++放前放后都可以，与27题不同 不建议这种，建议先写入再++
//                nums[head] = nums[tail];
//            }
//            tail++;
//        }
//
//        return head + 1;
//    }
//};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        int head = 1, tail = 1;
        while (tail < nums.size()) {
            if (nums[tail] != nums[tail - 1]) {
                nums[head++] = nums[tail];
            }
            tail++;
        }
        return head;
    }
};

int main() {
    Solution sl;
    vector<int> arr = { 1,1,1,2 };
    cout << "after remove, the length is :" << sl.removeDuplicates(arr);

    return 0;
}