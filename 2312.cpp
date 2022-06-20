// https://leetcode.cn/problems/selling-pieces-of-wood/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long sellingWood(int m, int n, vector<vector<int>>& prices) {
		vector<vector<long long>> grid(m + 1, vector<long long>(n + 1, 0));
		for (vector<int>& price : prices)
		{
			int h = price[0];
			int w = price[1];
			int v = price[2];
			grid[h][w] = v;
		}
		vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = grid[i][j];
				for (int k = 1; k < i; ++k)
				{
					dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
				}
				for (int k = 1; k < j; ++k)
				{
					dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
				}
			}
		}
		return dp[m][n];
	}
};

int main()
{
	int m = 3;
	int n = 5;
	vector<vector<int>> prices = {
		{1, 4, 2},
		{2, 2, 7},
		{2, 1, 3},
	};
	long long ans = Solution().sellingWood(m, n, prices);
	cout << ans << endl;
	return 0;
}

