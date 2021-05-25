// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if(head == nullptr)
		{
			return nullptr;
		}
		unordered_map<Node*, Node*> node_map;
		Node* ptr = head;
		while(ptr != nullptr)
		{
			node_map[ptr] = new Node(ptr->val);
			ptr = ptr->next;
		}
		for(pair<Node*, Node*> ptrs : node_map)
		{
			if(ptrs.first->next != nullptr)
			{
				ptrs.second->next = node_map[ptrs.first->next];
			}
			if(ptrs.first->random != nullptr)
			{
				ptrs.second->random = node_map[ptrs.first->random];
			}
		}
		return node_map[head];
	}
};
