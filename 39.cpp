// https://leetcode-cn.com/problems/combination-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& ans, vector<int>& indexs, const vector<int>& candidates, int target)
	{
		int size = indexs.size();
		int candidates_size = candidates.size();
		if(target == 0)
		{
			vector<int> nums(size);
			for(int i = 0; i < size; ++i)
			{
				nums[i] = candidates[indexs[i]];
				cout << nums[i] << " ";
			}
			cout << endl;
			ans.push_back(nums);
			return;
		}
		int start_index = 0;
		if(size > 0)
		{
			start_index = indexs[size - 1];
		}
		for(int i = start_index; i < candidates_size; ++i)
		{
			if(target >= candidates[i])
			{
				indexs.push_back(i);
				dfs(ans, indexs, candidates, target - candidates[i]);
				indexs.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> indexs;
		dfs(ans, indexs, candidates, target);
		return ans;
	}
};

int main()
{
	vector<int> candidates = {2, 3, 5};
	int target = 8;
	Solution().combinationSum(candidates, target);
	return 0;
}
