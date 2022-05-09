// https://leetcode.cn/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* slow = head;
		ListNode* fast = nullptr;
		if(slow != nullptr)
		{
			fast = slow->next;
		}
		while(slow != nullptr && fast != nullptr)
		{
			if(slow == head)
			{
				head = fast;
			}
			if(pre != nullptr)
			{
				pre->next = fast;
				slow->next = fast->next;
				fast->next = slow;
			}
			else
			{
				slow->next = fast->next;
				fast->next = slow;
			}
			pre = slow;
			slow = slow->next;
			if(slow != nullptr)
			{
				fast = slow->next;
			}
		}
		return head;
    }
};
