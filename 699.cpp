// https://leetcode.cn/problems/falling-squares/
#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeNode {
public:
	SegmentTreeNode(int left, int right, int value): left(left), right(right), value(value)
	{
		mid = (left + right) >> 1;
		delayValue = 0;
		leftNode = nullptr;
		rightNode = nullptr;
	}
	void makeChild()
	{
		if (leftNode == nullptr)
		{
			leftNode = new SegmentTreeNode(this->left, mid, 0);
		}
		if (rightNode == nullptr)
		{
			rightNode = new SegmentTreeNode(mid + 1, this->right, 0);
		}
	}
	int getValue()
	{
		return value;
	}
	int getValue(int left, int right)
	{
		if (left <= this->left && this->right <= right)
		{
			return getValue();
		}
		dealDelay();
		int value = 0;
		if (left <= mid)
		{
			value = max(value, leftNode->getValue(left, right));
		}
		if (right > mid)
		{
			value = max(value, rightNode->getValue(left, right));
		}
		return value;
	}
	void setValue(int left, int right, int value)
	{
		if (left > this->right || right < this->left)
		{
			return;
		}
		if (left <= this->left && this->right <= right)
		{
			delayValue = value;
			this->value = value;
			return;
		}
		dealDelay();
		if (left <= mid)
		{
			leftNode->setValue(left, right, value);
		}
		if (right > mid)
		{
			rightNode->setValue(left, right, value);
		}
		this->value = max(leftNode->getValue(), rightNode->getValue());
	}
	void dealDelay()
	{
		makeChild();
		if (delayValue)
		{
			leftNode->value = delayValue;
			leftNode->delayValue = delayValue;
			rightNode->value = delayValue;
			rightNode->delayValue = delayValue;
		}
		delayValue = 0;
	}
	int mid;
	int left;
	int right;
	int value;
	int delayValue;
	SegmentTreeNode* leftNode;
	SegmentTreeNode* rightNode;
};

class SegmentTree {
public:
	SegmentTree(int left, int right)
	{
		root = new SegmentTreeNode(left, right, 0);
	}
	~SegmentTree(){}
	void setValue(int left, int right, int value)
	{
		root->setValue(left, right, value);
	}
	int getValue()
	{
		return root->getValue();
	}
	int getValue(int left, int right)
	{
		return root->getValue(left, right);
	}
private:
	SegmentTreeNode* root;
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
		vector<int> ans;
		int n = positions.size();
		int minPosition = 0;
		int maxPosition = 1e8 * 2;
		SegmentTree segmentTree(minPosition, maxPosition);
		for (int i = 0;i < n; ++i)
		{
			int left = positions[i][0];
			int sideLength = positions[i][1];
			int right = left + sideLength - 1;
			int value = segmentTree.getValue(left, right);
			segmentTree.setValue(left, right, value + sideLength);
			ans.push_back(segmentTree.getValue());
		}
		return ans;
    }
};

int main()
{
	// vector<vector<int>> positions = {{1, 2}, {2, 3}, {6, 1}};
	// vector<vector<int>> positions = {{100, 100}, {200, 100}};
	// vector<vector<int>> positions = {{9, 6}, {2, 2}, {2, 6}};
	// vector<vector<int>> positions = {{9, 7}, {1, 9}, {3, 1}};
	vector<vector<int>> positions = {{4, 9}, {8, 8}, {6, 8}, {8, 2}, {1, 2}};
	vector<int> ans = Solution().fallingSquares(positions);
	int n = ans.size();
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
