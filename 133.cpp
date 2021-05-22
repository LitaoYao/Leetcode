// https://leetcode-cn.com/problems/clone-graph/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if(node == nullptr)
		{
			return nullptr;
		}
		unordered_map<Node*, Node*> node_map;
		queue<Node*> q;
		q.push(node);
		Node* now_node;
		while(!q.empty())
		{
			now_node = q.front();
			q.pop();
			cout << now_node->val << endl;
			node_map[now_node] = new Node(now_node->val, now_node->neighbors);
			for(Node* next_node : now_node->neighbors)
			{
				if(node_map.find(next_node) == node_map.end())
				{
					node_map[next_node] = nullptr;
					q.push(next_node);
				}
			}
		}
		int size;
		for(pair<Node*, Node*> now_node : node_map)
		{
			size = now_node.second->neighbors.size();
			for(int i = 0; i < size; ++i)
			{
				now_node.second->neighbors[i] = node_map[now_node.second->neighbors[i]];
			}
		}
		return node_map[node];
	}
};

int main()
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	node1->neighbors.push_back(node2);
	node1->neighbors.push_back(node4);
	node2->neighbors.push_back(node1);
	node2->neighbors.push_back(node3);
	node3->neighbors.push_back(node2);
	node3->neighbors.push_back(node4);
	node4->neighbors.push_back(node1);
	node4->neighbors.push_back(node3);
	Solution().cloneGraph(node2);
	return 0;
}
