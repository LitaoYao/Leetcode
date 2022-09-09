// https://leetcode.cn/problems/meeting-rooms-iii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int mostBooked(int n, vector<vector<int>>& meetings) {
		int m = meetings.size();
		sort(meetings.begin(), meetings.end());
		vector<int> counts(n, 0);
		vector<long long> endTime(n, 0);
		for (int i = 0; i < m; ++i)
		{
			int index = 0;
			for (int j = 0; j < n; ++j)
			{
				if (endTime[j] <= meetings[i][0])
				{
					index = j;
					break;
				}
				if (endTime[j] < endTime[index])
				{
					index = j;
				}
			}
			endTime[index] = max(endTime[index], (long long)meetings[i][0]) + meetings[i][1] - meetings[i][0];
			++counts[index];
		}
		int maxIndex = 0;
		for (int i = 0; i < n; ++i)
		{
			if (counts[i] > counts[maxIndex])
			{
				maxIndex = i;
			}
		}
		return maxIndex;
	}
};

int main()
{
	int n = 2;
	vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
	int ans = Solution().mostBooked(n, meetings);
	cout << ans << endl;
	return 0;
}
