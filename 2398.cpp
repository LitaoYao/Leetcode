// https://leetcode.cn/problems/maximum-number-of-robots-within-budget/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
		int n = chargeTimes.size();
		vector<long long> sum(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			sum[i] = sum[i - 1] + runningCosts[i - 1];
		}
		int left = 1;
		int right = n;
		int ans = 0;
		while (left <= right)
		{
			int k = (left + right) >> 1;
			deque<int> q;
			bool valid = false;
			for (int i = 0; i < n && !valid; ++i)
			{
				while (!q.empty() && i - q.front() + 1 > k)
				{
					q.pop_front();
				}
				while (!q.empty() && chargeTimes[i] > chargeTimes[q.back()])
				{
					q.pop_back();
				}
				q.push_back(i);
				if (i + 1 >= k && chargeTimes[q.front()] + (sum[i + 1] - sum[i - k + 1]) * k <= budget)
				{
					valid = true;
				}
			}
			if (valid)
			{
				ans = max(ans, k);
				left = k + 1;
			}
			else
			{
				right = k - 1;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> chargeTimes = {3, 6, 1, 3, 4};
	vector<int> runningCosts = {2, 1, 3, 4, 5};
	long long budget = 25;
	int ans = Solution().maximumRobots(chargeTimes, runningCosts, budget);
	cout << ans << endl;
	return 0;
}
