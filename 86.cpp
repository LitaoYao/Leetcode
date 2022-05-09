// https://leetcode.cn/problems/partition-list/
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
	ListNode* link(ListNode*& head, ListNode*& ptr, ListNode* new_ptr)
	{
		if(ptr == nullptr)
		{
			head = ptr = new_ptr;
		}
		else
		{
			ptr = ptr->next = new_ptr;
		}
		ListNode* next = ptr->next;
		ptr->next = nullptr;
		return next;
	}
	ListNode* partition(ListNode* head, int x) {
		ListNode* small = nullptr;
		ListNode* small_ptr = nullptr;
		ListNode* large = nullptr;
		ListNode* large_ptr = nullptr;
		ListNode* ptr = head;
		while(ptr != nullptr)
		{
			if(ptr->val < x)
			{
				ptr = link(small, small_ptr, ptr);
			}
			else
			{
				ptr = link(large, large_ptr, ptr);
			}
		}
		if(small_ptr != nullptr)
		{
			small_ptr->next = large;
		}
		else if(large != nullptr)
		{
			small = large;
		}
		for(ptr = small; ptr != nullptr; ptr = ptr->next)
		{
			cout << ptr->val << " ";
		}
		return small;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* ptr = head;
	ptr = ptr->next = new ListNode(4);
	ptr = ptr->next = new ListNode(3);
	ptr = ptr->next = new ListNode(2);
	ptr = ptr->next = new ListNode(5);
	ptr = ptr->next = new ListNode(2);
	Solution().partition(head, 3);
	return 0;
}
