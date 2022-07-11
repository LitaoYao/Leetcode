// https://leetcode.cn/problems/count-the-number-of-ideal-arrays/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int idealArrays(int n, int maxValue) {
		int mod = 1000000007;
		int maxLength = 20;
		vector<vector<int>> trans(maxValue + 1, vector<int>());
		vector<vector<int>> dp(maxValue + 1, vector<int>(maxLength, 0));
		vector<vector<long long>> C(n + 1, vector<long long>(maxLength, 0));
		long long ans = 0;
		// 求个因子
		for (int i = 1; i <= maxValue; ++i)
		{
			for (int j = i + i; j <= maxValue; j += i)
			{
				trans[j].push_back(i);
			}
		}
		// 求个组合数
		C[0][0] = 1;
		C[1][0] = 1;
		C[1][1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			C[i][0] = 1;
			for (int j = 1; j < maxLength && j <= i; ++j)
			{
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
			}
		}
		// 求个不重复的dp
		for (int i = 1; i <= maxValue; ++i)
		{
			dp[i][1] = 1;
			for (int j = 2; j < maxLength; ++j)
			{
				for (int k : trans[i])
				{
					dp[i][j] = (dp[i][j] + dp[k][j - 1]) % mod;
				}
			}
		}
		// 统计答案
		for (int i = 1; i <= maxValue; ++i)
		{
			for (int k = 1; k < maxLength; ++k)
			{
				ans = (ans + dp[i][k] * C[n - 1][k - 1]) % mod;
			}
		}
		return ans;
	}
};

int main()
{
	int n = 2;
	int maxValue = 5;
	int ans = Solution().idealArrays(n, maxValue);
	cout << ans << endl;
	return 0;
}

