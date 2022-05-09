// https://leetcode.cn/problems/triangle/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> dp(n);
		dp[n - 1] = triangle[0][0];
		for(int i = 1; i < n; ++i)
		{
			dp[n - i - 1] = dp[n - i] + triangle[i][0];
			for(int j = 1; j < i; ++j)
			{
				dp[n - i + j - 1] = min(dp[n - i + j - 1], dp[n - i + j]) + triangle[i][j];
			}
			dp[n - 1] = dp[n - 1] + triangle[i][i];
		}
		int ans = dp[0];
		for(int i = 1; i < n; ++i)
		{
			ans = min(ans, dp[i]);
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> triangle;
	triangle.push_back({2});
	triangle.push_back({3, 4});
	triangle.push_back({6, 5, 7});
	triangle.push_back({4, 1, 8, 3});
	cout << Solution().minimumTotal(triangle);
	return 0;
}
