// https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxValueOfCoins(vector<vector<int>>& piles, int k) {
		int n = piles.size();
		// vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		memset(dp, 0, sizeof(dp));
		int cnt_sum = 0;
		for(int i = 1; i <= n; ++i)
		{
			int m = piles[i - 1].size();
			for(int j = 0; j <= k; ++j)
			{
				cnt_sum = 0;
				dp[i][j] = dp[i - 1][j] + cnt_sum;
				for (int t = 1; t <= j && t <= m; ++t)
				{
					cnt_sum += piles[i - 1][t - 1];
					dp[i][j] = max(dp[i][j], dp[i - 1][j - t] + cnt_sum);
				}
			}
		}
		return dp[n][k];
	}

	int dp[1005][2005];
};

int main()
{
	Solution s = Solution();
	vector<vector<int>> piles({{1, 100, 3}, {7, 8, 9}});
	int k = 2;
	cout << s.maxValueOfCoins(piles, k);
	return 0;
}
