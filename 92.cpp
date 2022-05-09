// https://leetcode.cn/problems/reverse-linked-list-ii/
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
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if(head == nullptr)
		{
			return head;
		}
		ListNode* pre = nullptr;
		ListNode* ptr = head;
		ListNode* next = nullptr;
		ListNode* inner_head = nullptr;
		ListNode* inner_end = nullptr;
		ListNode* in = nullptr;
		int index = 1;
		while(index <= right)
		{
			if(index >= left)
			{
				if(index == left)
				{
					if(in != nullptr)
					{
						in->next = nullptr;
					}
					pre = ptr;
					inner_end = ptr;
					inner_head = ptr;
					ptr = ptr->next;
				}
				else
				{
					inner_head = ptr;
					next = ptr->next;
					ptr->next = pre;
					pre = ptr;
					ptr = next;
				}
			}
			else
			{
				in = ptr;
				ptr = ptr->next;
			}
			++index;
		}
		if(in)
		{
			in->next = inner_head;
		}
		else
		{
			head = inner_head;
		}
		inner_end->next = ptr;
		for(ptr = head; ptr != nullptr; ptr = ptr->next)
		{
			cout << ptr->val << " ";
		}
		return head;
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
	Solution().reverseBetween(head, 2, 4);
	return 0;
}
