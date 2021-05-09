// https://leetcode-cn.com/problems/sort-colors/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		int left1 = size;
		int right1 = 0;
		while(left <= right)
		{
			cout << left1 << " " << left << " " << right << " " << right1 << endl;
			cout << nums[left1] << " " << nums[left] << " " << nums[right] << " " << nums[right1] << endl;
			if(nums[left] == 0 && left1 < left)
			{
				swap(nums[left], nums[left1]);
				++left1;
			}
			if(nums[right] == 2 && right1 > right)
			{
				swap(nums[right], nums[right1]);
				--right1;
			}
			if(nums[left] == 2 && right1 > right)
			{
				swap(nums[left], nums[right1]);
				--right1;
			}
			if(nums[right] == 0 && left1 < left)
			{
				swap(nums[right], nums[left1]);
				++left1;
			}
			if(nums[left] > nums[right])
			{
				swap(nums[left], nums[right]);
			}
			if(left1 < size && nums[left1] != 1)
			{
				left1 = size;
			}
			if(right1 >= 0 && nums[right1] != 1)
			{
				right1 = 0;
			}
			if(nums[left] == 1)
			{
				left1 = min(left, left1);
				right1 = max(left, right1);
			}
			if(nums[right] == 1)
			{
				left1 = min(right, left1);
				right1 = max(right, right1);
			}
			if(nums[left] == nums[right])
			{
				if(nums[left] == 0)
				{
					++left;
				}
				else if(nums[left] == 2)
				{
					--right;
				}
				else
				{
					++left;
					--right;
				}
			}
			else
			{
				++left;
				--right;
			}
			for(int i = 0; i < size; ++i)
			{
				cout << nums[i] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	vector<int> nums = {2,2,1,2,1,1,1,0,0,2,1,0,2,1,2,2,1,1,1,1,1,0,2,0,2,0,2,2,1,0,2,1,0,2,1,2,0,0,0,0,2,1,1,2,0,1,2,2,0,0,2,2,0,1,0,1,0,0,1,1,1,0,0,2,2,2,1,0,0,2,1,0,1,0,2,2,1,2,1,1,2,1,1,0,0,2,1,0,0};
	int size = nums.size();
	for(int i = 0; i < size; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	Solution().sortColors(nums);
	return 0;
}
