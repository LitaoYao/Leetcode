// https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestSubsequence(string s, int k) {
		int n = s.size();
		vector<vector<long long>> dp(n, vector<long long>(n + 1, INT_MAX));
		dp[0][0] = 0;
		dp[0][1] = s[0] - '0';
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= i + 1; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j > 0 && dp[i - 1][j - 1] != INT_MAX)
				{
					long long num = (dp[i - 1][j - 1] << 1) + (s[i] - '0');
					if (num <= k)
					{
						dp[i][j] = min(num, dp[i][j]);
					}
				}
			}
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (dp[n - 1][j] != INT_MAX)
			{
				ans = j;
			}
		}
		return ans;
	}
};

int main()
{
	string s = "1001010";
	int k = 5;
	int ans = Solution().longestSubsequence(s, k);
	cout << ans << endl;
	return 0;
}

