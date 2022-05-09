// https://leetcode.cn/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	void dfs(vector<vector<int>>& ans, vector<int>& indexs, unordered_map<int, int> counts, const vector<int>& candidates, int target)
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
			if(target >= candidates[i] && counts[candidates[i]] > 0)
			{
				indexs.push_back(i);
				counts[candidates[i]] -= 1;
				dfs(ans, indexs, counts, candidates, target - candidates[i]);
				indexs.pop_back();
				counts[candidates[i]] += 1;
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		unordered_map<int, int> counts;
		vector<int> real_candidates;
		int size = candidates.size();
		for(int i = 0; i < size; ++i)
		{
			if(counts.find(candidates[i]) == counts.end())
			{
				counts[candidates[i]] = 0;
				real_candidates.push_back(candidates[i]);
			}
			counts[candidates[i]] += 1;
		}
		vector<vector<int>> ans;
		vector<int> indexs;
		dfs(ans, indexs, counts, real_candidates, target);
		return ans;
	}
};
int main()
{
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	Solution().combinationSum2(candidates, target);
	return 0;
}
