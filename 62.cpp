// https://leetcode.cn/problems/unique-paths/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> dp(n);
		dp[0] = 1;
		for(int i = 0; i < m; ++i)
		{
			for(int j = 1; j < n; ++j)
			{
				dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};
int main()
{
	cout << Solution().uniquePaths(7, 3);
	return 0;
}
