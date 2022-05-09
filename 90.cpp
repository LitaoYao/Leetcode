// https://leetcode.cn/problems/subsets-ii/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	// 方法1:计数法
	void dfs(
		const map<int, int>& counts,
		map<int, int>::iterator it,
		vector<vector<int>>& ans,
		vector<int>& group
	)
	{
		if(it == counts.end())
		{
			for(int num : group)
			{
				cout << num << " ";
			}
			cout << endl;
			ans.push_back(group);
			return;
		}
		for(int i = 0; i <= it->second; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				group.push_back(it->first);
			}
			++it;
			dfs(counts, it, ans, group);
			--it;
			for(int j = 0; j < i; ++j)
			{
				group.pop_back();
			}
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> group;
		map<int, int> counts;
		int size = nums.size();
		for(int i = 0; i < size; ++i)
		{
			if(counts.find(nums[i]) == counts.end())
			{
				counts[nums[i]] = 0;
			}
			++counts[nums[i]];
		}
		dfs(counts, counts.begin(), ans, group);
		return ans;
	}
	// 方法1:计数法

	// 方法2:标记法
	void dfs2(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& group, int index)
	{
		int size = nums.size();
		if(abs(index) == size)
		{
			for(int num : group)
			{
				cout << num << " ";
			}
			cout << endl;
			ans.push_back(group);
			return;
		}
		if(index >= 0 || nums[abs(index)] != nums[abs(index) - 1])
		{
			group.push_back(nums[abs(index)]);
			dfs2(nums, ans, group, abs(index) + 1);
			group.pop_back();
		}
		dfs2(nums, ans, group, -(abs(index) + 1));
	}
	vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> group;
		sort(nums.begin(), nums.end());
		dfs2(nums, ans, group, 0);
		return ans;
	}
	// 方法2:标记法
};

int main()
{
	vector<int> nums = {1, 2, 2};
	Solution().subsetsWithDup2(nums);
	return 0;
}
