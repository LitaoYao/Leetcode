// https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/
#include <iostream>
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
    void dfs(TreeNode* node, int& sum, int& count, int& ans)
    {
        if (node == NULL)
        {
            return;
        }
        int leftSum = 0;
        int leftCount = 0;
        dfs(node->left, leftSum, leftCount, ans);
        int rightSum = 0;
        int rightCount = 0;
        dfs(node->right, rightSum, rightCount, ans);
        sum = leftSum + rightSum + node->val;
        count = leftCount + rightCount + 1;
        if (sum / count == node->val)
        {
            ++ans;
        }
        return;
    }

    int averageOfSubtree(TreeNode* root) {
        int sum = 0;
        int count = 0;
        int ans = 0;
        dfs(root, sum, count, ans);
        return ans;
    }
};

int main()
{
	Solution s = Solution();
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(8);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right->right = new TreeNode(6);
	int ans = s.averageOfSubtree(root);
	cout << ans << endl;
	return 0;
}
