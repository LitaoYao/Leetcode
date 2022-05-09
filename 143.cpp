// https://leetcode.cn/problems/reorder-list/
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
	ListNode* reverseList(ListNode* head)
	{
		if(head == nullptr)
		{
			return nullptr;
		}
		ListNode* ptr = head;
		ListNode* pre_ptr = nullptr;
		ListNode* next_ptr = nullptr;
		while(ptr != nullptr)
		{
			next_ptr = ptr->next;
			ptr->next = pre_ptr;
			pre_ptr = ptr;
			ptr = next_ptr;
		}
		return pre_ptr;
	}
	void reorderList(ListNode* head) {
		if(head == nullptr)
		{
			return;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = reverseList(slow->next);
		slow->next = nullptr;
		slow = head;
		ListNode* next_slow = nullptr;
		ListNode* next_fast = nullptr;
		while(slow != nullptr && fast != nullptr)
		{
			next_slow = slow->next;
			next_fast = fast->next;
			slow->next = fast;
            fast->next = next_slow;
			slow = next_slow;
			fast = next_fast;
		}
		for(ListNode* ptr = head; ptr != nullptr; ptr = ptr->next)
		{
			cout << ptr->val << " ";
		}
		return;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* ptr = head;
	ptr = ptr->next = new ListNode(2);
	ptr = ptr->next = new ListNode(3);
	ptr = ptr->next = new ListNode(4);
	ptr = ptr->next = new ListNode(5);
	Solution().reorderList(head);
}
