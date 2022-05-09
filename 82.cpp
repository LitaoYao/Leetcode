// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* new_head = nullptr;
		ListNode* slow = nullptr;
		ListNode* fast = head;
		bool skip = false;
		while(fast != nullptr)
		{
			skip = false;
			while(fast->next && fast->next->val == fast->val)
			{
				skip = true;
				fast = fast->next;
			}
			if(!skip)
			{
				if(slow == nullptr)
				{
					new_head = fast;
				}
				else
				{
					slow->next = fast;
				}
				slow = fast;
			}
			else
			{
				if(slow != nullptr)
				{
					slow->next = nullptr;
				}
			}
			fast = fast->next;
		}
		for(ListNode* ptr = new_head; ptr != nullptr; ptr = ptr->next)
		{
			cout << ptr->val << " ";
		}
		return new_head;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* ptr = head;
	ptr = ptr->next = new ListNode(2);
	ptr = ptr->next = new ListNode(2);
	Solution().deleteDuplicates(head);
	return 0;
}
