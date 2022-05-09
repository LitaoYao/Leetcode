// https://leetcode.cn/problems/minimum-path-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<int> dp = grid[0];
		for(int j = 1; j < m; ++j)
		{
			dp[j] += dp[j - 1];
		}
		for(int i = 1; i < n; ++i)
		{
			dp[0] += grid[i][0];
			for(int j = 1; j < m; ++j)
			{
				dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
			}
		}
		return dp[m - 1];
	}
};

int main()
{
	vector<vector<int>> grid;
	grid.push_back({1, 3, 1});
	grid.push_back({1, 5, 1});
	grid.push_back({4, 2, 1});
	cout << Solution().minPathSum(grid);
	return 0;
}
