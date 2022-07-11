// https://leetcode.cn/problems/smallest-number-in-infinite-set/
#include <iostream>
#include <vector>
using namespace std;

class SmallestInfiniteSet {
public:
	SmallestInfiniteSet() {
		nums = vector<int>(1001, 0);
		for (int i = 1; i <= 1000; ++i)
		{
			nums[i] = 1;
		}
	}

	int popSmallest() {
		for (int i = 1; i <= 1000; ++i)
		{
			if (nums[i] == 1)
			{
				nums[i] = 0;
				return i;
			}
		}
		return -1;
	}

	void addBack(int num) {
		nums[num] = 1;
	}
	vector<int> nums;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main()
{
	SmallestInfiniteSet smallestInfiniteSet = SmallestInfiniteSet();
	smallestInfiniteSet.addBack(2);    // 2 已经在集合中，所以不做任何变更。
	cout << smallestInfiniteSet.popSmallest() << endl; // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
	cout << smallestInfiniteSet.popSmallest() << endl; // 返回 2 ，并将其从集合中移除。
	cout << smallestInfiniteSet.popSmallest() << endl; // 返回 3 ，并将其从集合中移除。
	smallestInfiniteSet.addBack(1);    // 将 1 添加到该集合中。
	cout << smallestInfiniteSet.popSmallest() << endl; // 返回 1 ，因为 1 在上一步中被添加到集合中，
	// 且 1 是最小的整数，并将其从集合中移除。
	cout << smallestInfiniteSet.popSmallest() << endl; // 返回 4 ，并将其从集合中移除。
	cout << smallestInfiniteSet.popSmallest() << endl; // 返回 5 ，并将其从集合中移除。
	return 0;
}

