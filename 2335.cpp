// https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int fillCups(vector<int>& amount) {
		int ans = 0;
		while (amount[0] > 0 || amount[1] > 0 || amount[2] > 0)
		{
			sort(amount.begin(), amount.end());
			if (amount[1] > 0)
			{
				--amount[1];
				--amount[2];
				++ans;
			}
			else
			{
				--amount[2];
				++ans;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> amount = {5, 4, 4};
	int ans = Solution().fillCups(amount);
	cout << ans << endl;
	return 0;
}

