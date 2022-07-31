// https://leetcode.cn/problems/design-a-number-container-system/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class NumberContainers {
public:
	NumberContainers() {
	}

	void change(int index, int number) {
		if (nums.count(index))
		{
			int num = nums[index];
			indexs[num].erase(index);
			if (indexs[num].size() == 0)
			{
				indexs.erase(num);
			}
		}
		nums[index] = number;
		indexs[number].insert(index);
	}

	int find(int number) {
		if (indexs.count(number))
		{
			return *indexs[number].begin();
		}
		return -1;
	}

	map<int, int> nums;
	map<int, set<int>> indexs;
};

int main()
{
	NumberContainers* obj = new NumberContainers();
	cout << obj->find(10) << endl;
	obj->change(2, 10);
	obj->change(1, 10);
	obj->change(3, 10);
	obj->change(5, 10);
	cout << obj->find(10) << endl;
	obj->change(1, 20);
	cout << obj->find(10) << endl;
	return 0;
}
