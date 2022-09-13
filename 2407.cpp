// https://leetcode.cn/problems/longest-increasing-subsequence-ii/
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int left;
	int right;
	int val;
	int delayDelta;
	int delayUpdate;
	bool update;
	Node* leftChild;
	Node* rightChild;
	Node(int left, int right, int val):
		left(left), right(right), val(val),
		delayDelta(0), delayUpdate(0), update(false),
		leftChild(nullptr), rightChild(nullptr){}
	int getMid()
	{
		return (left + right) >> 1;
	}
};

class SegTree {
public:
	SegTree(int left, int right)
	{
		root = new Node(left, right, 0);
	}
	void update(int left, int right, int val)
	{
		update(root, left, right, val);
	}
	void delta(int left, int right, int val)
	{
		delta(root, left, right, val);
	}
	int query(int left, int right)
	{
		return query(root, left, right);
	}
private:
	void ensureChild(Node* node)
	{
		if (node->left != node->right)
		{
			int mid = node->getMid();
			if (node->leftChild == nullptr)
			{
				node->leftChild = new Node(node->left, mid, 0);
			}
			if (node->rightChild == nullptr)
			{
				node->rightChild = new Node(mid + 1, node->right, 0);
			}
		}
	}
	void pushUp(Node* node)
	{
		if (node->left != node->right)
		{
			node->val = max(node->leftChild->val, node->rightChild->val);
		}
	}
	void pushDown(Node* node)
	{
		if (node->left != node->right)
		{
			if (node->update)
			{
				node->leftChild->update = true;
				node->leftChild->delayUpdate = node->delayUpdate;
				node->leftChild->delayDelta = 0;
				node->rightChild->update = true;
				node->rightChild->delayUpdate = node->delayUpdate;
				node->rightChild->delayDelta = 0;
			}
			if (node->delayDelta)
			{
				node->leftChild->delayDelta += node->delayDelta;
				node->rightChild->delayDelta += node->delayDelta;
			}
		}
	}
	void update(Node* node, int val)
	{
		node->val = val;
		node->delayUpdate = val;
		node->update = true;
		node->delayDelta = 0;
	}
	void update(Node* node, int left, int right, int val)
	{
		if (node->left == left && node->right == right)
		{
			update(node, val);
			return;
		}
		ensureChild(node);
		pushDown(node);
		int mid = node->getMid();
		if (right <= mid)
		{
			update(node->leftChild, left, right, val);
		}
		else if (left > mid)
		{
			update(node->rightChild, left, right, val);
		}
		else
		{
			update(node->leftChild, left, mid, val);
			update(node->rightChild, mid + 1, right, val);
		}
		pushUp(node);
	}
	void delta(Node* node, int val)
	{
		node->val += val;
		node->delayDelta += val;
	}
	void delta(Node* node, int left, int right, int val)
	{
		if (node->left == left && node->right == right)
		{
			delta(node, val);
			return;
		}
		ensureChild(node);
		pushDown(node);
		int mid = node->getMid();
		if (right <= mid)
		{
			delta(node->leftChild, left, right, val);
		}
		else if (left > mid)
		{
			delta(node->rightChild, left, right, val);
		}
		else
		{
			delta(node->leftChild, left, mid, val);
			delta(node->rightChild, mid + 1, right, val);
		}
		pushUp(node);
	}
	int query(Node* node, int left, int right)
	{
		ensureChild(node);
		pushDown(node);
		if (node->left == left && node->right == right)
		{
			return node->val;
		}
		int mid = node->getMid();
		if (right <= mid)
		{
			return query(node->leftChild, left, right);
		}
		else if (left > mid)
		{
			return query(node->rightChild, left, right);
		}
		else
		{
			int leftVal = query(node->leftChild, left, mid);
			int rightVal = query(node->rightChild, mid + 1, right);
			return max(leftVal, rightVal);
		}
	}
private:
	Node* root;
};

class Solution {
public:
	int lengthOfLIS(vector<int>& nums, int k) {
		int n = nums.size();
		int maxVal = *max_element(nums.begin(), nums.end());
		vector<int> dp(maxVal + 1, 0);
		SegTree tree(0, maxVal);
		dp[nums[0]] = 1;
		tree.update(nums[0], nums[0], 1);
		for (int i = 1; i < n; ++i)
		{
			int left = max(0, nums[i] - k);
			int right = max(0, nums[i] - 1);
			int maxLen = tree.query(left, right);
			dp[nums[i]] = max(dp[nums[i]], maxLen + 1);
			tree.update(nums[i], nums[i], dp[nums[i]]);
		}
		return *max_element(dp.begin(), dp.end());
	}
};

int main()
{
	vector<int> nums = {4, 2, 1, 4, 3, 4, 5, 8, 15};
	int k = 3;
	int ans = Solution().lengthOfLIS(nums, k);
	cout << ans << endl;
	return 0;
}
