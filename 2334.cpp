// https://leetcode.cn/problems/subarray-with-elements-greater-than-varying-threshold/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int findRoot(vector<int>& groups, int x)
	{
		if (groups[x] == x || groups[x] == -1)
		{
			return groups[x];
		}
		return groups[x] = findRoot(groups, groups[x]);
	}
	void mergeGroup(vector<int>& groups, map<int, int>& groupSizes, int i, int j)
	{
		int rooti = findRoot(groups, i);
		int rootj = findRoot(groups, j);
		if (rooti == -1 || rootj == -1)
		{
			return;
		}
		groups[rooti] = rootj;
		groupSizes[rootj] += groupSizes[rooti];
		groupSizes.erase(rooti);
	} 
	int validSubarraySize(vector<int>& nums, int threshold) {
		int n = nums.size();
		vector<pair<int, int>> needs(n);
		vector<int> groups(n, -1);
		map<int, int> groupSizes;
		for (int i = 0; i < n; ++i)
		{
			needs[i] = {threshold / nums[i] + 1, i};
		}
		sort(needs.begin(), needs.end());
		for (int k = 1, i = 0; k <= n; ++k)
		{
			while (i < n && needs[i].first <= k)
			{
				int index = needs[i].second;
				groups[index] = index;
				groupSizes[index] = 1;
				if (index > 0)
				{
					mergeGroup(groups, groupSizes, index, index - 1);
				}
				if (index < n - 1)
				{
					mergeGroup(groups, groupSizes, index, index + 1);
				}
				int root = findRoot(groups, index);
				if (groupSizes[root] >= k)
				{
					return k;
				}
				++i;
			}
		}
		return -1;
	}
};

int main()
{
	vector<int> nums = {1, 3, 4, 3, 1};
	int threshold = 6;
	int ans = Solution().validSubarraySize(nums, threshold);
	cout << ans << endl;
	return 0;
}

