// https://leetcode.cn/problems/unique-binary-search-trees-ii/
#include <iostream>
#include <vector>
using namespace std;

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
	vector<TreeNode*> dfs(int left, int right)
	{
		vector<TreeNode*> ans;
		vector<TreeNode*> left_ans;
		vector<TreeNode*> right_ans;
		if(left > right)
		{
			ans.push_back(nullptr);
			return ans;
		}
		TreeNode* node;
		for(int i = left; i <= right; ++i)
		{
			left_ans = dfs(left, i - 1);
			right_ans = dfs(i + 1, right);
			int left_size = left_ans.size();
			int right_size = right_ans.size();
			for(int j = 0; j < left_size; ++j)
			{
				for(int k = 0; k < right_size; ++k)
				{
					node = new TreeNode(i);
					node->left = left_ans[j];
					node->right = right_ans[k];
					ans.push_back(node);
				}
			}
		}
		return ans;
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans = dfs(1, n);
		cout << ans.size();
		return dfs(1, n);
	}
};

int main()
{
	Solution().generateTrees(3);
	return 0;
}
