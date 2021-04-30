// https://leetcode-cn.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* now_node = nullptr;
        int now_num = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 != nullptr)
            {
                now_num += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                now_num += l2->val;
                l2 = l2->next;
            }
            if(ans == nullptr)
            {
                now_node = new ListNode(now_num % 10);
                ans =  now_node;
            }
            else
            {
                now_node->next = new ListNode(now_num % 10);
                now_node = now_node->next;
            }
            now_num = now_num / 10;
        }
        if(now_num != 0)
        {
            now_node->next = new ListNode(now_num % 10);
        }
        return ans;
    }
};

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	cout << Solution().addTwoNumbers(l1, l2)->val << endl;
	return 0;
}
