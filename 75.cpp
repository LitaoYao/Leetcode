// https://leetcode-cn.com/problems/sort-colors/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int size = nums.size();
		int index = 0;
		int left = 0;
		int right = size - 1;
		while(index <= right)
		{
			while(index <= right && nums[index] == 2)
			{
				swap(nums[index], nums[right--]);
			}
			if(nums[index] == 0)
			{
				swap(nums[index], nums[left++]);
			}
			index += 1;
		}
	}
};

int main()
{
	vector<int> nums = {2,2,1,2,1,1,1,0,0,2,1,0,2,1,2,2,1,1,1,1,1,0,2,0,2,0,2,2,1,0,2,1,0,2,1,2,0,0,0,0,2,1,1,2,0,1,2,2,0,0,2,2,0,1,0,1,0,0,1,1,1,0,0,2,2,2,1,0,0,2,1,0,1,0,2,2,1,2,1,1,2,1,1,0,0,2,1,0,0};
	Solution().sortColors(nums);
	return 0;
}
