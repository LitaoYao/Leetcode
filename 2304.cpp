// https://leetcode.cn/problems/minimum-path-cost-in-a-grid/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
		for (int j = 0; j < m; ++j)
		{
			dp[0][j] = grid[0][j];
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					int cost = moveCost[grid[i - 1][j]][k];
					dp[i][k] = min(dp[i - 1][j] + cost + grid[i][k], dp[i][k]);
				}
			}
		}
		int ans = INT_MAX;
		for (int j = 0; j < m; ++j)
		{
			ans = min(ans, dp[n - 1][j]);
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> grid = {{5, 3}, {4, 0}, {2, 1}};
	vector<vector<int>> moveCost = {{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
	int ans = Solution().minPathCost(grid, moveCost);
	cout << ans << endl;
	return 0;
}

