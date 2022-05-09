// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
using namespace std;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		
	}
	
	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		index_map[val].insert(nums.size());
		nums.push_back(val);
		return index_map[val].size() == 1;
	}
	
	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if(index_map[val].empty()) return false;
		int index = *(index_map[val].begin());
		index_map[val].erase(index);
		if(index != nums.size() - 1){
			int back = nums.back();
			nums[index] = back;
			index_map[back].erase(nums.size() - 1);
			index_map[back].insert(index);
		}
		nums.pop_back();
		return true;
	}
	
	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
private:
	vector<int> nums;
	unordered_map<int, unordered_set<int> > index_map;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{
	RandomizedCollection* obj = new RandomizedCollection();
	bool param_1 = obj->insert(1);
	bool param_2 = obj->remove(1);
	bool param_3 = obj->insert(1);
	int param_4 = obj->getRandom();
	return 0;
}
