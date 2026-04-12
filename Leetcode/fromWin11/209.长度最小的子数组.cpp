#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>


class Solution {
public:
    int minSubArrayLen(int target, std::vector<int> &nums) {
        int sum = 0;
        int n = nums.size();
        int h = 0;
        int minlen = INT_MAX;
        for (int t = 0; t < n; t++) {
            sum += nums[t];
            while (sum >= target) {
                minlen = std::min(t - h, minlen);
                sum -= nums[h++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};


int main() {
    std::vector<int> nums = { 5,1,3,5,10,7,4,9,2,8 };
    int target = 15;
    Solution sl;
    std::cout << "minlen: " << sl.minSubArrayLen(target, nums);
}