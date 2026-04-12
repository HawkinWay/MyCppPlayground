#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//直接排序法 O(nlogn)
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        vector<int> result;
//        for (int i = 0; i < nums.size(); i++) {
//            result.push_back(pow(nums[i], 2));          //pow(x,n) x的n次方       sqrt(n)  n的平方根
//        }
//        sort(result.begin(), result.end());
//        return result;
//    }
//};


//双指针O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int index = nums.size() - 1;
        int head = 0, tail = nums.size() - 1;
        while(head <= tail) {
            if (abs(nums[head]) > abs(nums[tail])) {        //abs(n) n的绝对值
                result[index--] = nums[head] * nums[head];
                head++;
            }
            else {
                result[index--] = nums[tail] * nums[tail];
                tail--;
            }
        }
        return result;
    }
};

int main() {
    vector<int> arr = { -4,-1,0,3,10 };

    Solution sl;
    vector<int> res = sl.sortedSquares(arr);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}

