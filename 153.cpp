// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = (left + right) >> 1;
		int ans = INT_MAX;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			ans = min(ans, nums[mid]);
			if(nums[left] == nums[right])
			{
				ans = min(ans, nums[left]);
				++left;
				--right;
			}
			else if(nums[left] > nums[mid] || nums[right] > nums[left])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return ans;
    }
};

int main()
{
	vector<int> nums = {4,5,6,7,1,2,2,3};
	cout << Solution().findMin(nums);
}
