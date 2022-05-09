// https://leetcode.cn/problems/insertion-sort-list/
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
	ListNode* insertionSortList(ListNode* head) {
		if(head == nullptr)
		{
			return nullptr;
		}
		ListNode* fake_head = new ListNode();
		fake_head->next = head;
		ListNode* last = head;
		ListNode* ptr = head->next;;
		while(ptr != nullptr)
		{
			if(last->val <= ptr->val)
			{
				last = last->next;
			}
			else
			{
				ListNode* pre = fake_head;
				while(pre->next->val <= ptr->val)
				{
					pre = pre->next;
				}
				last->next = ptr->next;
				ptr->next = pre->next;
				pre->next = ptr;
			}
			ptr = last->next;
		}
		head = fake_head->next;
		delete fake_head;
		for(ListNode* p = head; p != nullptr; p = p->next)
		{
			cout << p->val << " ";
		}
		return head;
	}
};

int main()
{
	ListNode* head = new ListNode(4);
	ListNode* ptr = head;
	ptr = ptr->next = new ListNode(2);
	ptr = ptr->next = new ListNode(1);
	ptr = ptr->next = new ListNode(3);
	Solution().insertionSortList(head);
	return 0;
}
