// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
	TreeNode* _sortedListToBST(ListNode* head, ListNode* end)
	{
		if(head == end)
		{
			return nullptr;
		}
		ListNode* slow = head;
		ListNode* fast = head->next;
		while(fast != end && fast->next != end)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* node = new TreeNode(slow->val);
		node->left = _sortedListToBST(head, slow);
		node->right = _sortedListToBST(slow->next, end);
		return node;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		return _sortedListToBST(head, nullptr);
	}
};

int main()
{
	return 0;
}
