// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if(size <= 2)
		{
			return size;
		}
		int front = 2;
		for(int i = 2; i < size; ++i)
		{
			if(nums[i] != nums[front - 2])
			{
				swap(nums[i], nums[front]);
				++front;
			}
		}
		for(int i = 0; i < front; ++i)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
		return front;
	}
};

int main()
{
	vector<int> nums = {1,1,1,2,2,2,3,3};
	cout << Solution().removeDuplicates(nums);
}
