// https://leetcode-cn.com/problems/minimum-rounds-to-complete-all-tasks/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		map<int, size_t> counts;
		size_t n = tasks.size();
		size_t maxCount = 5;
		for (size_t i = 0; i < n; ++i)
		{
			if (!counts.count(tasks[i]))
			{
				counts[tasks[i]] = 0;
			}
			++counts[tasks[i]];
			maxCount = max(maxCount, counts[tasks[i]]);
		}
		vector<int> dp(maxCount + 1, 0);
		dp[2] = dp[3] = 1;
		dp[4] = 2;
		for (size_t i = 5; i <= maxCount; ++i)
		{
			dp[i] = min(dp[i - 2], dp[i - 3]) + 1;
		}
		int ans = 0;
		for (auto iter = counts.begin(); iter != counts.end(); ++iter)
		{
			if (iter->second == 1)
			{
				return -1;
			}
			ans += dp[iter->second];
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> tasks = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
	int ans = s.minimumRounds(tasks);
	cout << ans << endl;
	return 0;
}
