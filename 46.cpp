// https://leetcode.cn/problems/permutations/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void next_permute(vector<int>& nums)
	{
		int size = nums.size();
		int pivot = size - 2;
		while(pivot >= 0 && nums[pivot] >= nums[pivot + 1])
		{
			--pivot;
		}
		reverse(nums.begin() + pivot + 1, nums.end());
		if(pivot >= 0)
		{
			for(int i = pivot + 1; i < size; ++i)
			{
				if(nums[i] > nums[pivot])
				{
					swap(nums[pivot], nums[i]);
					break;
				}
			}
		}
		return;
	}
	vector<vector<int>> permute(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> ans;
		while(true)
		{
			for(int i = 0; i < size; ++i)
			{
				cout << nums[i] << " ";
			}
			cout << endl;
			ans.push_back(nums);
			next_permute(nums);
			bool repeat = true;
			for(int i = 0; i < size; ++i)
			{
				if(nums[i] != ans[0][i])
				{
					repeat = false;
				}
			}
			if(repeat)
			{
				break;
			}
		}
		return ans;
	}
};
int main()
{
	vector<int> nums = {2, 3, 1};
	Solution().permute(nums);
	return 0;
}
