// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans(2);
		ans[0] = ans[1] = -1;
		int size = nums.size();
		if(size == 0)
		{
			return ans;
		}
		int left = 0;
		int right = size - 1;
		int min_right = right;
		int mid = (left + right) >> 1;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			if(nums[mid] == target)
			{
				if(mid > left && nums[mid - 1] == target)
				{
					right = mid - 1;
				}
				else
				{
					break;
				}
			}
			else if(nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
				min_right = right;
			}
		}
		if(nums[mid] == target)
		{
			ans[0] = mid;
		}
		else
		{
			return ans;
		}
		left = mid;
		right = min_right;
		mid = (left + right) >> 1;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			if(nums[mid] == target)
			{
				if(mid < right && nums[mid + 1] == target)
				{
					left = mid + 1;
				}
				else
				{
					break;
				}
			}
			else if(nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if(nums[mid] == target)
		{
			ans[1] = mid;
		}
		cout << ans[0] << " " << ans[1] << endl;
		return ans;
	}
};

int main()
{
	vector<int> nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	Solution().searchRange(nums, target);
}
