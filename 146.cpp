// https://leetcode.cn/problems/lru-cache/
#include <iostream>
#include <unordered_map>
using namespace std;

struct TwoWayListNode {
	int key;
	int val;
	TwoWayListNode *next;
	TwoWayListNode *pre;
	TwoWayListNode(int key, int val) : key(key), val(val), next(nullptr), pre(nullptr) {}
	TwoWayListNode() : next(nullptr), pre(nullptr) {}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		head = new TwoWayListNode();
		end = new TwoWayListNode();
		head->next = end;
		end->pre = head;
		count = 0;
	}

	void update(TwoWayListNode* ptr)
	{
		TwoWayListNode* pre = ptr->pre;
		TwoWayListNode* next = ptr->next;
		if(pre != nullptr)
		{
			pre->next = next;
		}
		if(next != nullptr)
		{
			next->pre = pre;
		}
		ptr->next = head->next;
		ptr->pre = head;
		head->next->pre = ptr;
		head->next = ptr;
	}

	int get(int key) {
		if(vals.count(key))
		{
			TwoWayListNode* ptr = vals[key];
			update(ptr);
			return ptr->val;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		TwoWayListNode* ptr;
		if(vals.count(key))
		{
			ptr = vals[key];
			ptr->val = value;
		}
		else
		{
			ptr = new TwoWayListNode(key, value);
			vals[key] = ptr;
			++count;
			if(count > capacity)
			{
				TwoWayListNode* delete_ptr = end->pre;
				delete_ptr->pre->next = end;
				end->pre = delete_ptr->pre;
				vals.erase(delete_ptr->key);
				delete delete_ptr;
				count = capacity;
			}
		}
		update(ptr);
	}
private:
	int count;
	int capacity;
	unordered_map<int, TwoWayListNode*> vals;
	TwoWayListNode* head;
	TwoWayListNode* end;
};

int main()
{
	LRUCache lRUCache = LRUCache(3);
	lRUCache.put(1, 1);
	cout << lRUCache.get(1) << endl;   
	lRUCache.put(2, 2);
	cout << lRUCache.get(1) << endl;   
	lRUCache.put(3, 3);
	lRUCache.put(4, 4);
	cout << lRUCache.get(4) << endl;   
	cout << lRUCache.get(3) << endl;   
	cout << lRUCache.get(2) << endl;   
	cout << lRUCache.get(1) << endl;   
	lRUCache.put(5, 5);
	cout << lRUCache.get(1) << endl;   
	cout << lRUCache.get(2) << endl;   
	cout << lRUCache.get(3) << endl;   
	cout << lRUCache.get(4) << endl;   
	cout << lRUCache.get(5) << endl;   
	return 0;
}
