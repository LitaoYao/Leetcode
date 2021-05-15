// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
	TreeNode* buildSubTree(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int post_left, int post_right)
	{
		if(post_left > post_right)
		{
			return nullptr;
		}
		int root_index = find(inorder.begin() + in_left, inorder.end() + in_right, postorder[post_right]) - inorder.begin();
		int new_post_left = post_right - (in_right - root_index);
		TreeNode* node = new TreeNode(postorder[post_right]);
		node->left = buildSubTree(inorder, in_left, root_index - 1, postorder, post_left, new_post_left - 1);
		node->right = buildSubTree(inorder, root_index + 1, in_right, postorder, new_post_left, post_right - 1);
		return node;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildSubTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

int main()
{
	vector<int> inorder = {9, 3, 15, 20, 7};
	vector<int> postorder = {9, 15, 7, 20, 3};
	Solution().buildTree(inorder, postorder);
	return 0;
}
