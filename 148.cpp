// https://leetcode.cn/problems/sort-list/
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
	// 快排法
	ListNode* partialSort(ListNode* left, ListNode* right)
	{
		if(left == right || left == nullptr)
		{
			return left;
		}
		ListNode* mid = left;
		ListNode* new_left = left;
		ListNode* new_right = left;
		ListNode* ptr = left->next;
		ListNode* pre = ptr;
		left->next = nullptr;
		ListNode* next;
		bool already_sorted = true;
		while(ptr != nullptr)
		{
			if(pre->val > ptr->val)
			{
				already_sorted = false;
			}
			next = ptr->next;
			if(ptr->val < mid->val)
			{
				already_sorted = false;
				ptr->next = new_left;
				new_left = ptr;
			}
			else
			{
				ptr->next = nullptr;
				new_right->next = ptr;
				new_right = ptr;
			}
			pre = ptr;
			ptr = next;
		}
		if(already_sorted)
		{
			return left;
		}
		next = mid->next;
		mid->next = nullptr;
		left = partialSort(new_left, mid);
		right = partialSort(next, new_right);
		ptr = left;
		while(ptr != nullptr && ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = right;
		return left;
	}
	ListNode* sortListQuickSort(ListNode* head) {
		ListNode* ptr = head;
		while(ptr != nullptr && ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		head = partialSort(head, ptr);
		return head;
	}

	// 归并法
	ListNode* sortList(ListNode* head)
	{
		if(head == nullptr)
		{
			return nullptr;
		}
		int size = 0;
		ListNode* ptr = head;
		while(ptr != nullptr)
		{
			ptr = ptr->next;
			++size;
		}
		ListNode* fakeHead = new ListNode(-1, head);
		for(int i = 1; i < size; i <<= 1)
		{
			ListNode* pre = fakeHead;
			ptr = fakeHead->next;
			while(ptr != nullptr)
			{
				ListNode* head1 = ptr;
				ptr = passN(head1, i);
				ListNode* head2 = ptr->next;
				ptr->next = nullptr;
				ptr = passN(head2, i);
				ListNode* next = nullptr;
				if(ptr != nullptr)
				{
					next = ptr->next;
					ptr->next = nullptr;
				}
				ListNode* mergedHead = mergeList(head1, head2);
				pre->next = mergedHead;
				while(pre->next != nullptr)
				{
					pre = pre->next;
				}
				ptr = next;
			}
		}
		ptr = fakeHead->next;
		delete fakeHead;
		return ptr;
	}

	ListNode* passN(ListNode* ptr, int n)
	{
		int i = 1;
		while(i < n && ptr != nullptr && ptr->next != nullptr)
		{
			ptr = ptr->next;
			++i;
		}
		return ptr;
	}

	ListNode* mergeList(ListNode* head1, ListNode* head2)
	{
		ListNode* fakeHead = new ListNode();
		ListNode* ptr = fakeHead;
		while(head1 != nullptr && head2 != nullptr)
		{
			if(head1->val < head2->val)
			{
				ptr = ptr->next = head1;
				head1 = head1->next;
			}
			else
			{
				ptr = ptr->next = head2;
				head2 = head2->next;
			}
		}
		if(head1 != nullptr)
		{
			ptr->next = head1;
		}
		else
		{
			ptr->next = head2;
		}
		ptr = fakeHead->next;
		delete fakeHead;
		return ptr;
	}
};

int main()
{
	ListNode* head = new ListNode(4);
	ListNode* ptr = head;
	ptr = ptr->next = new ListNode(2);
	ptr = ptr->next = new ListNode(1);
	ptr = ptr->next = new ListNode(3);
	head = Solution().sortList(head);
	ptr = head;
	while(ptr != nullptr)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	return 0;
}
