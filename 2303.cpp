// https://leetcode.cn/problems/calculate-amount-paid-in-taxes/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double calculateTax(vector<vector<int>>& brackets, int income) {
		int n = brackets.size();
		int cost = 0;
		double ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (income < brackets[i][0])
			{
				ans += (income - cost) * brackets[i][1] / 100.0;
				break;
			}
			ans += (brackets[i][0] - cost) * brackets[i][1] / 100.0;
			cost = brackets[i][0];
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> brackets = {{3, 50}, {7, 10}, {12, 25}};
	int income = 10;
	double ans = Solution().calculateTax(brackets, income);
	cout << ans << endl;
	return 0;
}

