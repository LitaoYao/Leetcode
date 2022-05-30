// https://leetcode.cn/problems/maximum-total-importance-of-roads/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	long long maximumImportance(int n, vector<vector<int>>& roads) {
		vector<vector<long long>> degrees(n, vector<long long>(2, 0));
		for (int i = 0; i < n; ++i)
		{
			degrees[i][1] = i;
		}
		for (auto road : roads)
		{
			degrees[road[0]][0]++;
			degrees[road[1]][0]++;
		}
		sort(degrees.begin(), degrees.end());
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans += degrees[i][0] * (i + 1);
		}
		return ans;
	}
};

int main()
{
	int n = 5;
	vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
	long long ans = Solution().maximumImportance(n, roads);
	cout << ans << endl;
	return 0;
}
