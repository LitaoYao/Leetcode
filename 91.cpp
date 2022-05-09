// https://leetcode.cn/problems/decode-ways/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int size = s.size();
		if(size == 0 || s[0] == '0')
		{
			return 0;
		}
		vector<int> dp(size + 1);
		dp[0] = 1;
		for(int i = 1; i <= size; ++i)
		{
			if(s[i - 1] != '0')
			{
				dp[i] = dp[i - 1];
			}
			if(i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
			{
				dp[i] += dp[i - 2];
			}
		}
		return dp[size];
	}
};

int main()
{
	cout << Solution().numDecodings("226");
	return 0;
}
