// https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfWays(int startPos, int endPos, int k) {
		vector<vector<long long>> dp(k + 1, vector<long long>(4000, 0));
		int offset = 1010;
		dp[0][startPos + offset] = 1;
		int mod = 1000000007;
		for (int i = 1; i <= k; ++i)
		{
			for (int x = -1000; x <= 2000; ++x)
			{
				int pos = x + offset;
				dp[i][pos] = (dp[i - 1][pos - 1] + dp[i - 1][pos + 1]) % mod;
			}
		}
		return dp[k][endPos + offset] % mod;
	}
};

int main()
{
	int startPos = 1;
	int endPos = 2;
	int k = 3;
	int ans = Solution().numberOfWays(startPos, endPos, k);
	cout << ans << endl;
	return 0;
}
