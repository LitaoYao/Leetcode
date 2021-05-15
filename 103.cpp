// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<TreeNode*> level_node;
		queue<pair<TreeNode*, int>> q;
		pair<TreeNode*, int> node;
		int level = 0;
		int level_count = 0;
		q.push(make_pair(root, 0));
		while(!q.empty())
		{
			node = q.front();
			level = node.second;
			level_node = vector<TreeNode*>();
			while(!q.empty())
			{
				node = q.front();
				q.pop();
				if(node.first != nullptr)
				{
					if(level >= ans.size())
					{
						ans.push_back(vector<int>());
					}
					ans[level].push_back(node.first->val);
					level_node.push_back(node.first);
				}
			}
			level_count = level_node.size();
			for(int i = level_count - 1; i >= 0; --i)
			{
				if((level & 1) == 1)
				{
					q.push(make_pair(level_node[i]->left, level + 1));
					q.push(make_pair(level_node[i]->right, level + 1));
				}
				else
				{
					q.push(make_pair(level_node[i]->right, level + 1));
					q.push(make_pair(level_node[i]->left, level + 1));
				}
			}
		}
		return ans;
	}
};

int main()
{
	return 0;
}
