// https://leetcode.cn/problems/count-number-of-texts/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countTexts(string pressedKeys) {
		int MOD = 1000000000 + 7;
		int counts[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
		int n = pressedKeys.size();
		vector<long long> dp(n, 0);
		for (int i = 0; i < n; ++i)
		{
			int nowNum = pressedKeys[i] - '0';
			for (int j = i; j > i - counts[nowNum] && j >= 0 && pressedKeys[j] == pressedKeys[i]; --j)
			{
				if (j == 0)
				{
					dp[i] += 1;
				}
				else
				{
					dp[i] += dp[j - 1];
				}
				dp[i] %= MOD;
			}
		}
		return dp[n - 1];
	}
};

int main()
{
	Solution s = Solution();
	string pressedKeys = "22233";
	// ans : 8 
	int ans = s.countTexts(pressedKeys);
	cout << ans << endl;
	pressedKeys = "222222222222222222222222222222222222";
	// ans : 82876089
	ans = s.countTexts(pressedKeys);
	cout << ans << endl;
	return 0;
}
