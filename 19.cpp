// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/ 
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pre_ptr = nullptr;
		ListNode* ptr = head;
		ListNode* fast_ptr = head;
		for(int i = 0; i < n; ++i)
		{
			fast_ptr = fast_ptr->next;
		}
		while(fast_ptr != nullptr)
		{
			pre_ptr = ptr;
			ptr = ptr->next;
			fast_ptr = fast_ptr->next;
		}
		if(pre_ptr != nullptr)
		{
			pre_ptr->next = ptr->next;
		}
		else
		{
			head = head -> next;
		}
		delete ptr;
		return head;
	}
};

int main()
{
	return 0;
}
