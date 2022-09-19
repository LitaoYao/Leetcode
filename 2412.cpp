// https://leetcode.cn/problems/minimum-money-required-before-transactions/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	long long minimumMoney(vector<vector<int>>& transactions) {
		int n = transactions.size();
		long long totalLost = 0;
		for (int i = 0; i < n; ++i)
		{
			if (transactions[i][0] > transactions[i][1])
			{
				totalLost += transactions[i][0] - transactions[i][1];
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (transactions[i][0] > transactions[i][1])
			{
				ans = max(ans, transactions[i][1] + totalLost);
			}
			else
			{
				ans = max(ans, transactions[i][0] + totalLost);
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> transactions = { {2, 1}, {5, 0}, {4, 2} };
	long long ans = Solution().minimumMoney(transactions);
	cout << ans << endl;
	return 0;
}
