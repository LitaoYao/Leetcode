// https://leetcode.cn/problems/QO5KpG/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct SegTreeNode
{
	int from;
	int to;
	int color;
	int redCount;
	SegTreeNode *left;
	SegTreeNode *right;
	SegTreeNode(int _from, int _to, int _color) : from(_from), to(_to), color(_color), redCount(0), left(NULL), right(NULL) {}
};

class Solution {
public:
	int draw(SegTreeNode* node, int color, int from, int to)
	{
		if (node->color == color)
		{
			return node->redCount;
		}
		if (from <= node->from && to >= node->to)
		{
			node->color = color;
			if (node->color == 1)
			{
				node->redCount = node->to - node->from + 1;
			}
			else
			{
				node->redCount = 0;
			}
			return node->redCount;
		}
		int mid = (node->from + node->to) >> 1;
		if (node->left == NULL)
		{
			node->left = new SegTreeNode(node->from, mid, node->color);
		}
		if (node->right == NULL)
		{
			node->right = new SegTreeNode(mid + 1, node->to, node->color);
		}
		if(node->color != -1)
		{
			node->left->color = node->color;
			node->right->color = node->color;
			if (node->color == 1)
			{
				node->left->redCount = mid - node->from + 1;
				node->right->redCount = node->to - mid;
			}
			else
			{
				node->left->redCount = 0;
				node->right->redCount = 0;
			}
		}
		node->color = -1;
		node->redCount = 0;
		if (to <= mid)
		{
			draw(node->left, color, from, to);
		}
		else if (from > mid)
		{
			draw(node->right, color, from, to);
		}
		else
		{
			draw(node->left, color, from, mid);
			draw(node->right, color, mid + 1, to);
		}
		node->redCount = node->left->redCount + node->right->redCount;
		return node->redCount;
	}
	void dfs(TreeNode* treeNode, vector<int>& nums)
	{
		if (treeNode->left)
		{
			dfs(treeNode->left, nums);
		}
		nums.push_back(treeNode->val);
		if (treeNode->right)
		{
			dfs(treeNode->right, nums);
		}
	}
	int getIndex(vector<int>& nums, int x)
	{
		int left = 0;
		int right = nums.size() - 1;
		while(left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] >= x)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
	int getNumber(TreeNode* root, vector<vector<int>>& ops) {
		vector<int> nums;
		dfs(root, nums);
		int m = nums.size();
		SegTreeNode* segRoot = new SegTreeNode(0, m - 1, 0);
		int n = ops.size();
		int color, from, to;
		for (int i = 0; i < n; ++i)
		{
			if (ops[i][1] > nums[m - 1] || ops[i][2] < nums[0])
			{
				continue;
			}
			color = ops[i][0];
			from = getIndex(nums, ops[i][1]);
			to = getIndex(nums, ops[i][2]);
			if (nums[to] > ops[i][2])
			{
				--to;
			}
			if (from > to)
			{
				continue;
			}
			draw(segRoot, color, from, to);
		}
		return segRoot->redCount;
	}
};

int main()
{
	/*
		[1,null,2,null,3,null,4,null,5]
		[[1,2,4],[1,1,3],[0,3,5]]
		[4,2,7,1,null,5,null,null,null,null,6]
		[[0,2,2],[1,1,5],[0,4,5],[1,5,7]]
	*/
	Solution s = Solution();
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	node->right = new TreeNode(2);
	node = node->right;
	node->right = new TreeNode(3);
	node = node->right;
	node->right = new TreeNode(4);
	node = node->right;
	node->right = new TreeNode(5);
	vector<vector<int>> ops = {{1, 2, 4}, {1, 1, 3}, {0, 3, 5}};
	cout << s.getNumber(root, ops);
	return 0;
}
