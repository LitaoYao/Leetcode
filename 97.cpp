// https://leetcode-cn.com/problems/interleaving-string/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.size();
		int l2 = s2.size();
		int l3 = s3.size();
		if(l3 != l1 + l2)
		{
			return false;
		}
		vector<vector<bool>> dp(l2 + 1, vector<bool>(l1 + 1, false));
		dp[0][0] = true;
		for(int i = 0; i <= l2; ++i)
		{
			for(int j = 0; j <= l1; ++j)
			{
				if(i > 0 && s2[i - 1] == s3[(i + j) - 1])
				{
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
				if(j > 0 && s1[j - 1] == s3[(i + j) - 1])
				{
					dp[i][j] = dp[i][j] || dp[i][j - 1];
				}
			}
		}
		return dp[l2][l1];
    }
};

int main()
{
	cout << Solution().isInterleave("cacccaa", "acccaacabbbab", "accccaaaccccabbaabab");
}
