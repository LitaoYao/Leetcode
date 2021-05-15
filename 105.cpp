// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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
	TreeNode* buildSubTree(
		vector<int>& preorder,
		int pre_left,
		int pre_right,
		vector<int>& inorder,
		int in_left,
		int in_right
	)
	{
		if(pre_left > pre_right)
		{
			return nullptr;
		}
		int root_index = find(inorder.begin() + in_left, inorder.begin() + in_right, preorder[pre_left]) - inorder.begin();
		int new_pre_right = pre_left + root_index - in_left; 
		TreeNode* node = new TreeNode(inorder[root_index]);
		node->left = buildSubTree(preorder, pre_left + 1, new_pre_right, inorder, in_left, root_index - 1); 
		node->right = buildSubTree(preorder, new_pre_right + 1, pre_right, inorder, root_index + 1, in_right);
		return node;
	}

	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
		return buildSubTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	// 方法2:迭代法
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int in_index = 0;
		stack<TreeNode*> s;
		int size = preorder.size();
		TreeNode* head;
		TreeNode* root;
		if(size == 0)
		{
			return nullptr;
		}
		head = root = new TreeNode(preorder[0]);
		s.push(root);
		for(int i = 1; i < size; ++i)
		{
			root = s.top();
			if(inorder[in_index] != s.top()->val)
			{
				root->left = new TreeNode(preorder[i]);
				s.push(root->left);
			}
			else
			{
				while(!s.empty() && s.top()->val == inorder[in_index])
				{
					root = s.top();
					s.pop();
					++in_index;
				}
				root->right = new TreeNode(preorder[i]);
				s.push(root->right);
			}
		}
		return head;
	}
};

int main()
{
	vector<int> preorder = {3, 9, 20, 15, 7};
	vector<int> inorder = {9, 3, 15, 20, 7};
	Solution().buildTree(preorder, inorder);
	return 0;
}
