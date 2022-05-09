// https://leetcode.cn/problems/subsets/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void doSubsets(vector<vector<int>>& ans, const vector<int>& nums, int index, vector<int>& group)
	{
		int size = nums.size();
		ans.push_back(group);
		int g_size = group.size();
		for(int i = 0; i < g_size; ++i)
		{
			cout << group[i] << " ";
		}
		cout << endl;
		if(index == size)
		{
			return;
		}
		for(int i = index; i < size; ++i)
		{
			group.push_back(nums[i]);
			doSubsets(ans, nums, i + 1, group);
			group.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> group;
		doSubsets(ans, nums, 0, group);
		return ans;
	}
};

int main()
{
	vector<int> nums = {1, 2, 3};
	Solution().subsets(nums);
	return 0;
}
