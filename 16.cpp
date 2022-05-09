// https://leetcode.cn/problems/3sum-closest/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int sum, ans=INT_MAX, left, right;
		for(int i = 0; i < size - 2; ++i)
		{
			if(i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			left = i + 1;
			right = size - 1;
			while(left < right)
			{
				sum = nums[i] + nums[left] + nums[right];
				if(abs(sum - target) < abs(ans - target))
				{
					ans = sum;
				}
				if(sum == target)
				{
					return target;
				}
				else if(sum < target)
				{
					++left;
					while(left < right && nums[left] == nums[left - 1])
					{
						++left;
					}
				}
				else
				{
					--right;
					while(left < right && nums[right] == nums[right + 1])
					{
						--right;
					}
				}
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums({1,1,-1,-1,3});
	cout << Solution().threeSumClosest(nums, 3);
	return 0;
}
