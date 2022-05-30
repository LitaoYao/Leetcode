// https://leetcode.cn/problems/booking-concert-tickets-in-groups/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BookMyShow {
public:
	struct SegTreeNode {
		SegTreeNode* leftNode;
		SegTreeNode* rightNode;
		int left;
		int right;
		long long val;
		long long min;
	};

	void createChild(SegTreeNode* node)
	{
		int mid = (node->left + node->right) >> 1;
		if (node->leftNode == nullptr)
		{
			node->leftNode = new SegTreeNode();
			node->leftNode->left = node->left;
			node->leftNode->right = mid;
		}
		if (node->rightNode == nullptr)
		{
			node->rightNode = new SegTreeNode();
			node->rightNode->left = mid + 1;
			node->rightNode->right = node->right;
		}
	}
	void modify(SegTreeNode* node, int index, long long delta)
	{
		if (index < node->left || index > node->right)
		{
			return;
		}
		if (index == node->left && index == node->right)
		{
			node->val += delta;
			node->min = node->val;
			return;
		}
		createChild(node);
		int mid = (node->left + node->right) >> 1;
		if (index <= mid)
		{
			modify(node->leftNode, index, delta);
		}
		else
		{
			modify(node->rightNode, index, delta);
		}
		node->val = node->leftNode->val + node->rightNode->val;
		node->min = min(node->leftNode->min, node->rightNode->min);
	}
	long long get(SegTreeNode* node, int left, int right)
	{
		if (right < node->left || node->right < left)
		{
			return 0;
		}
		if (left <= node->left && node->right <= right)
		{
			return node->val;
		}
		createChild(node);
		return get(node->leftNode, left, right) + get(node->rightNode, left, right);
	}
	long long getMin(SegTreeNode* node, int left, int right)
	{
		if (right < node->left || node->right < left)
		{
			return INT_MAX;
		}
		if (left <= node->left && node->right <= right)
		{
			return node->min;
		}
		createChild(node);
		return min(getMin(node->leftNode, left, right), getMin(node->rightNode, left, right));
	}
	BookMyShow(int n, int m) {
		seats = vector<long long>(n, 0);
		root = new SegTreeNode();
		root->left = 0;
		root->right = n - 1;
		root->val = 0;
		N = n;
		M = m;
	}

	vector<int> gather(int k, int maxRow) {
		vector<int> res;
		if (M - getMin(root, 0, maxRow) < k)
		{
			return res;
		}
		int front = 0;
		int back = maxRow;
		while (front < back)
		{
			int mid = (front + back) >> 1;
			if (M - getMin(root, 0, mid) < k)
			{
				front = mid + 1;
			}
			else
			{
				back = mid;
			}
		}
		res.push_back(front);
		res.push_back(seats[front]);
		seats[front] += k;
		modify(root, front, k);
		return res;
	}

	bool scatter(int k, int maxRow) {
		if ((long long)(maxRow + 1) * M - get(root, 0, maxRow) < k)
		{
			return false;
		}
		int nowRow = 0;
		int nowK = 0;
		while (nowK < k && nowRow <= maxRow)
		{
			int pushK = min((long long)(k - nowK), M - seats[nowRow]);
			nowK += pushK;
			seats[nowRow] += pushK;
			modify(root, nowRow, pushK);
			++nowRow;
		}
		return true;
	}
	int N;
	int M;
	vector<long long> seats;
	SegTreeNode* root;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

void printSeat(vector<int>& seat)
{
	cout << "{";
	if (seat.size() == 2)
	{
		cout << seat[0] << ", " << seat[1];
	}
	cout << "}";
	cout << endl;
}

int main()
{
	int n = 2;
	int m = 5;
	BookMyShow* obj = new BookMyShow(n, m);
	vector<int> param_1;
	bool param_2;
	param_1 = obj->gather(4, 0);
	printSeat(param_1);
	param_1 = obj->gather(2, 0);
	printSeat(param_1);
	param_2 = obj->scatter(5, 1);
	cout << param_2 << endl;
	param_2 = obj->scatter(5, 1);
	cout << param_2 << endl;
	return 0;
}
