// https://leetcode-cn.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();
		vector<vector<int>> dp(n);
		for(int i = 0; i < n; ++i)
		{
			dp[i] = vector<int>(m);
			dp[i][0] = obstacleGrid[i][0] == 0 && (i == 0 || dp[i - 1][0]);
		}
		for(int j = 1; j < m; ++j)
		{
			dp[0][j] = obstacleGrid[0][j] == 0 && dp[0][j - 1];
		}
		for(int i = 1; i < n; ++i)
		{
			for(int j = 1; j < m; ++j)
			{
				if(obstacleGrid[i][j])
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};

int main()
{
	vector<vector<int>> obstacleGrid;
	obstacleGrid.push_back({0, 0, 0});
	obstacleGrid.push_back({0, 1, 0});
	obstacleGrid.push_back({0, 0, 0});
	cout << Solution().uniquePathsWithObstacles(obstacleGrid);
	return 0;
}
