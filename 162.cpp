// https://leetcode-cn.com/problems/find-peak-element/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while(left < right - 1)
		{
			int mid = (left + right) >> 1;
			if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
			{
				break;
			}
			else if(nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if(left + 1 >= right)
		{
			return nums[left] > nums[right] ? left : right;
		}
		return (left + right) >> 1;
	}
};

int main()
{
	vector<int> nums = {1, 2};
	cout << Solution().findPeakElement(nums);
	return 0;
}
