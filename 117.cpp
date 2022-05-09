// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		if(root == nullptr)
		{
			return root;
		}
		if(root->left != nullptr)
		{
			if(root->right != nullptr)
			{
				root->left->next = root->right;
			}
			else
			{
				Node* node = root;
				while(node->next != nullptr)
				{
					if(node->next->left != nullptr)
					{
						root->left->next = node->next->left;
						break;
					}
					else if(node->next->right != nullptr)
					{
						root->left->next = node->next->right;
						break;
					}
					node = node->next;
				}
			}
		}
		if(root->right != nullptr)
		{
			Node* node = root;
			while(node->next != nullptr)
			{
				if(node->next->left != nullptr)
				{
					root->right->next = node->next->left;
					break;
				}
				else if(node->next->right != nullptr)
				{
					root->right->next = node->next->right;
					break;
				}
				node = node->next;
			}
		}
		connect(root->right);
		connect(root->left);
		return root;
	}
};
