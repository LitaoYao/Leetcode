// https://leetcode.cn/problems/search-in-rotated-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = (left + right) >> 1;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			if(nums[mid] == target)
			{
				return mid;
			}
			if(nums[left] == target)
			{
				return left;
			}
			if(nums[right] == target)
			{
				return right;
			}
			if(nums[left] == nums[right])
			{
				++left;
				--right;
			}
			else if(target > nums[mid])
			{
				if(nums[left] > nums[mid] && target > nums[right])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else// if(target < nums[mid])
			{
				if(nums[mid] > nums[right] && target < nums[left])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		if(nums[mid] == target)
		{
			return mid;
		}
		else
		{
			return -1;
		}
    }
};

int main()
{
	vector<int> nums = {4,5,6,7,8,1,2,3};
	cout << Solution().search(nums, 8);
}
