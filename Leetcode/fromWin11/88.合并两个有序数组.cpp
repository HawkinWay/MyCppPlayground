#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        for (int i = 0; i < n; i++) {
            nums1[m] = nums2[i];
            m++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    vector<int> arr1 = { 1 }, arr2 = {  };
    Solution sl;
    sl.merge(arr1, 1, arr2, 0);
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}