// https://leetcode.cn/problems/substring-with-largest-variance/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int calcPairPower(string& s, int n, char a, char b)
	{
		if (a == b)
		{
			return 0;
		}
		int dp = 0; // dp表示子序列最大差值，可能不含b，所以需要一个dpB来表示包含b的最大差值
		int dpB = -2; // 包含b的最大差值，依赖dp，因为dp最小为-1，所以取一个比-1小的为初始值就好
		int maxPower = 0;
		for(int i = 0; i < n; ++i)
		{
			if (s[i] == a)
			{
				++dp;
				if (dpB >= -1)
				{
					++dpB;
				}
			}
			else if (s[i] == b)
			{
				--dp;
				dpB = dp; // 包含b了，可以开始算dpB了，dp最小为-1，赋值给dpB相当于激活了dpB的动态规划
				if (dp < 0)
				{
					dp = 0;
				}
			}
			if (dpB > maxPower)
			{
				maxPower = dpB;
			}
		}
		return maxPower;
	}
	int largestVariance(string s) {
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				ans = max(ans, calcPairPower(s, n, 'a' + i, 'a' + j));
			}
		}
		return ans;
	}
};

int main()
{
	string s = "abbb";
	int ans = Solution().largestVariance(s);
	cout << ans << endl;
	return 0;
}
