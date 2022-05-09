// https://leetcode.cn/problems/rotate-list/
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
	ListNode* rotateRight(ListNode* head, int k) {
		if(head == nullptr)
		{
			return nullptr;
		}
		ListNode* ptr = head;
		int size = 1;
		while(ptr->next != nullptr)
		{
			ptr = ptr->next;
			++size;
		}
		ptr->next = head;
		for(int i = 0; i < size - (k % size); ++i)
		{
			ptr = ptr->next;
		}
		head = ptr->next;
		ptr->next = nullptr;
		return head;
	}
};

int main()
{
	ListNode* head = nullptr;
	ListNode* ptr = nullptr;
	head = ptr = new ListNode(1);
	ptr->next = new ListNode(2);
	ptr = ptr->next;
	ptr->next = new ListNode(3);
	ptr = ptr->next;
	ptr->next = new ListNode(4);
	ptr = ptr->next;
	ptr->next = new ListNode(5);
	ptr = ptr->next;
	ListNode* new_head = Solution().rotateRight(head, 2);
	ptr = new_head;
	while(ptr != nullptr)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	return 0;
}
