#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right){}
};



class Solution{
public:
	vector<int> rightSideView(TreeNode* root){
		// BST (or levelorder) method

		vector<vector<int>> result;
		if(root == nullptr)	return {};

		queue<TreeNode*> q;
		q.push(root);

		while(!q.empty()){
			int levelSize = q.size();
			vector<int> currentLevel;

			for(int i = 0; i < levelSize; i++){
				TreeNode* node = q.front();
				q.pop();

				currentLevel.push_back(node->val);
				
				if(node->left != nullptr)	q.push(node->left);
				if(node->right != nullptr)	q.push(node->right);
			}

			result.push_back(currentLevel);
		}
		
		vector<int> ans;
		for(const auto& res : result){
			int n = res.size();
			ans.push_back(res[n - 1]);
		}
		
		return ans;
	}
};
