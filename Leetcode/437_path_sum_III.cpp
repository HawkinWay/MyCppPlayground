#include <unordered_map>

// Binary Tree, Prefix, Backtrack

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // current_sum - previous_sum = targetSum 
    std::unordered_map<long long, int> mp;  // current_sum in a path : frequency of occurrence
    int target_sum;
    int count{0};

    void dfs(TreeNode* root, long long current_sum){
        if(root == nullptr)     return;
        current_sum += root->val;
        if(mp.find(current_sum - target_sum) != mp.end()){
            count += mp[current_sum - target_sum];
        }
        mp[current_sum]++;

        dfs(root->left, current_sum);
        dfs(root->right, current_sum);
        mp[current_sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target_sum = targetSum;
        mp[0] = 1;
        dfs(root, 0);
        return count;
    }
};