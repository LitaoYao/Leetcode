// https://leetcode.cn/problems/strictly-palindromic-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool check(vector<int>& x)
	{
		int n = x.size();
		for (int i = 0; i < n; ++i)
		{
			if (x[i] != x[n - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	vector<int> toB(int n, int b)
	{
		vector<int> ans;
		while (n > 1)
		{
			ans.push_back(n % b);
			n /= b;
		}
		ans.push_back(n);
		return ans;
	}
	bool isStrictlyPalindromic(int n) {
		for (int b = 2; b <= n - 2; ++b)
		{
			vector<int> tmp = toB(n, b);
			if (!check(tmp))
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	int n = 9;
	bool ans = Solution().isStrictlyPalindromic(n);
	cout << ans << endl;
	return 0;
}
