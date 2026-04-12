#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
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
    void helper(TreeNode* root, vector<int> &res) {
        if (root) {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root,result);
        return result;
    }
};

TreeNode* Creat() {
    TreeNode* r;
    int n;
    cin >> n;
    if (n == 0)
        return  nullptr;
    else {
        r = new TreeNode;
        r->val = n;
        r->left = Creat();
        r->right = Creat();
    }
    return r;
}

int main() {
    TreeNode* root;
    cout << "ÇëÊäÈë½áµã£º";
    root = Creat();
    cout << endl;

    Solution sl;
    vector<int> show = sl.inorderTraversal(root);
    for (int i = 0; i < show.size(); i++) {
        cout << show.at(i) << " ";
    }
    cout << endl;

	return 0;
}