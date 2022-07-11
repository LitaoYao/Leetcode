// https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
		sort(buses.begin(), buses.end());
		sort(passengers.begin(), passengers.end());
		int n = buses.size();
		int m = passengers.size();
		vector<vector<int>> real(n, vector<int>());
		int nowBus = 0;
		vector<int> que;
		for (int i = 0; i < m; ++i)
		{
			int t = passengers[i];
			while (nowBus < n && (buses[nowBus] < t || real[nowBus].size() >= capacity))
			{
				++nowBus;
			}
			if (nowBus == n)
			{
				break;
			}
			real[nowBus].push_back(t);
			que.push_back(t);
		}
		int ans = -1;
		int lastSize = real[n - 1].size();
		if ((lastSize > 0 && real[n - 1][lastSize - 1] == buses[n - 1]) || lastSize >= capacity)
		{
			int qSize = que.size();
			for (int i = qSize - 1; i > 0; --i)
			{
				if (que[i] - que[i - 1] > 1)
				{
					ans = que[i] - 1;
					break;
				}
			}
			if (ans == -1)
			{
				ans = que[0] - 1;
			}
		}
		else
		{
			ans = buses[n - 1];
		}
		return ans;
	}
};

int main()
{
	vector<int> buses = {10, 20};
	vector<int> passengers = {2, 17, 18, 19};
	int capacity = 2;
	int ans = Solution().latestTimeCatchTheBus(buses, passengers, capacity);
	cout << ans << endl;
	return 0;
}

