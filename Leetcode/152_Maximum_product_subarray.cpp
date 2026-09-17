#include <vector>
#include <iostream>
using namespace std;

// dpMax[i]/dpMin[i]: the max/min product subarray up to i

class Solution{
public:
	int maxProduct(vector<int>& nums){
		int n = nums.size();
		vector<int> dpMax(n, 0), dpMin(n, 0);
		dpMax[0] = nums[0];
		dpMin[0] = nums[0];
		int ans{nums[0]};

		for(int i = 1; i < n; i++){
			dpMax[i] = max(dpMax[i - 1] * nums[i], max(nums[i], dpMin[i - 1] * nums[i]));
			dpMin[i] = max(dpMax[i - 1] * nums[i], max(nums[i], dpMin[i - 1] * nums[i]));

			ans = max(ans, dpMax[i]);
		}

		return ans;
	}
};
