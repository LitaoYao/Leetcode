// https://leetcode.cn/problems/total-appeal-of-a-string/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long appealSum(string s) {
		int n = s.size();
		vector<int> preIndex(n, -1);
		vector<int> lastIndex(27, -1);
		for (int i = 0; i < n; ++i)
		{
			preIndex[i] = lastIndex[s[i] - 'a'];
			lastIndex[s[i] -'a'] = i; 
		}
		vector<long long> dp(n, 0);
		dp[0] = 1;
		long long ans = 1;
		for (int i = 1; i < n; ++i)
		{
			dp[i] = dp[i - 1] + (i - preIndex[i]);
			ans += dp[i];
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	string str = "abbca";
	long long ans = s.appealSum(str);
	cout << ans << endl;
	return 0;
}
