#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


//±©Á¦Ã¶¾Ù O(n^2)
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size() - 1; i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (nums.at(i) + nums.at(j) == target) {
//                    return { i,j };
//                }
//            }
//        }
//        return {};
//    }
//};
//int main() {
//    Solution sl;
//    int nums[] = { 2,4,6 };
//    vector<int> vec(begin(nums), end(nums));
//    vector<int> result = sl.twoSum(vec, 6);
//    if (!result.empty()) {
//        cout << "[" << result.at(0) << "," << result.at(1) << "]" << endl;
//    }
//    else {
//        cout << "Not found!" << endl;
//    }
//
//    return 0;
//}


//¹þÏ£±í
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator it = u.find(target - nums[i]);
            if (it != u.end()) {
                return{ it->second,i };
            }
            u[nums[i]] = i;
        }
        return{};
    }
};

int main() {
    vector<int> v = { 2,4,6 };
    Solution sl;
    vector<int> res = sl.twoSum(v, 6);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
}