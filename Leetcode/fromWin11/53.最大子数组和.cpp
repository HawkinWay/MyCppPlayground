#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//贪心算法（当前和<0 ,丢弃前面的数组，从下一个数重新开始；当前和≥0 , 继续往后加，可能会变更大）
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int sum = 0, mx = nums[0];
//        int p = 0;
//        while (p < nums.size()) {
//            if (sum < 0) {
//                sum = 0;
//            }
//            sum += nums[p];
//            if (sum > mx) {
//                mx = sum;
//            }
//            else {
//                mx = mx;
//            }
//            p++;
//        }
//        return mx;
//    }
//};

//动态规划（前一个元素大于零，加到当前元素上）
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            mx = max(mx, sum);
        }
        return mx;
    }
};

int main() {
    vector<int> arr1 = { -2,1,-3,4,-1,2,1,-5,4 };  //6
    vector<int> arr2 = { -1 };                    //-1
    vector<int> arr3 = { 1,2,-1,-2,2,1,-2,1,4,-5,4 };   //6
      
    Solution sl;
    int res1 = sl.maxSubArray(arr1);
    int res2 = sl.maxSubArray(arr2);
    int res3 = sl.maxSubArray(arr3);

    cout << res1 << "\n" << res2 << "\n" << res3 << endl;
    return 0;
}

