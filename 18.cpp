// https://leetcode.cn/problems/4sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> group(4);
		int sum, left, right;
		int size = nums.size();
		for(int i = 0; i < size - 3; ++i)
		{
			while(i > 0 && nums[i] == nums[i - 1])
			{
				++i;
			}
			sum = nums[i];
			group[0] = nums[i];
			for(int j = i + 1; j < size - 2; ++j)
			{
				while(j > i + 1 && nums[j] == nums[j - 1])
				{
					++j;
				}
				sum += nums[j];
				group[1] = nums[j];
				left = j + 1;
				right = size - 1;
				while(left < right)
				{
					group[2] = nums[left];
					group[3] = nums[right];
					sum += nums[left] + nums[right];
					if(sum == target)
					{
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
					else if(sum < target)
					{
						++left;
					}
					else
					{
						--right;
					}
					sum -= group[2] + group[3];
				}
				sum -= nums[j];
			}
		}
		return ans;
    }
};

int main()
{
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	Solution().fourSum(nums, 0);
	return 0;
}
