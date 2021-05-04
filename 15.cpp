// https://leetcode-cn.com/problems/3sum/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int sum, left, right;
		vector<vector<int>> ans;
		vector<int> group(3);
		for(int i = 0; i < size - 2; ++i)
		{
			group[0] = nums[i];
			if(i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			left = i + 1;
			right = size - 1;
			while(left < right)
			{
				sum = nums[i] + nums[left] + nums[right];
				if(sum == 0)
				{
					group[1] = nums[left];
					group[2] = nums[right];
					ans.push_back(group);
					++left;
					while(left < right && nums[left] == nums[left - 1])
					{
						++left;
					}
					--right;
					while(left < right && nums[right] == nums[right + 1])
					{
						--right;
					}
				}
				else if(sum < 0)
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
	vector<int> nums({-1, 1, 0});
	Solution().threeSum(nums);
	return 0;
}
