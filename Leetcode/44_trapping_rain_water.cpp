#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2)  return 0;
        int sum = 0;
        int left = 0, right = n - 1;
        int leftMax = height[left], rightMax = height[right];
        while(left < right){
            if(height[left] < height[right]){
                left++;
                leftMax = max(leftMax, height[left]);
                sum += leftMax - height[left];
            }else{
                right--;
                rightMax = max(rightMax, height[right]);
                sum += right - height[right];
            }
        }
        return sum;
    }
};

int main(){
    vector<int> rain{4,2,0,3,2,5};
    Solution sl;
    cout << "output: " << sl.trap(rain);
}