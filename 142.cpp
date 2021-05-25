// https://leetcode-cn.com/problems/linked-list-cycle-ii/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(head == nullptr)
		{
			return nullptr;
		}
		ListNode* slow = head;
		ListNode* fast = slow->next;
		while(fast != nullptr && fast->next != nullptr && fast->next != slow->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		if(fast != nullptr && fast->next == slow->next)
		{
			slow = head;
			fast = fast->next;
			while(slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
		else
		{
			return nullptr;
		}
	}
};


int main()
{
	ListNode* ptr1 = new ListNode(3);
	ListNode* ptr2 = new ListNode(2);
	ListNode* ptr3 = new ListNode(0);
	ListNode* ptr4 = new ListNode(-4);
	ListNode* head = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;
	ptr3->next = ptr4;
	ptr4->next = ptr2;
	ListNode* in = Solution().detectCycle(head);
	if(in != nullptr)
	{
		cout << in->val;
	}
}
