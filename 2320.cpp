// https://leetcode.cn/problems/count-number-of-ways-to-place-houses/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countHousePlacements(int n) {
		int mod = 1000000007;
		vector<vector<long long>> dp(n, vector<long long>(2, 0));
		dp[0][0] = 1;
		dp[0][1] = 1;
		for (int i = 1; i < n; ++i)
		{
			dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
			dp[i][1] = dp[i - 1][0];
		}
		long long ans = (dp[n - 1][0] + dp[n - 1][1]);
		ans = ans * ans % mod;
		return ans;
	}
};

int main()
{
	int n = 2;
	int ans = Solution().countHousePlacements(n);
	cout << ans << endl;
	return 0;
}

