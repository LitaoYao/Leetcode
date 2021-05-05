// https://leetcode-cn.com/problems/next-permutation/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		int i = size - 1;
		while(i > 0 && nums[i] <= nums[i - 1])
		{
			i--;
		}
		reverse(nums.begin() + i, nums.end());
		if(i > 0)
		{
			for(int j = i; j < size; ++j)
			{
				if(nums[j] > nums[i - 1])
				{
					swap(nums[i - 1], nums[j]);
					break;
				}
			}
		}
	}
};
