// https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int minimumObstacles(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<long long>> minCost(n, vector<long long>(m, INT_MAX));
		minCost[0][0] = grid[0][0];
		queue<long long> q;
		q.push(0);
		int ways[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
		while (!q.empty())
		{
			int i = q.front() / 1000000;
			int j = q.front() % 1000000;
			q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int nexti = i + ways[k][0];
				int nextj = j + ways[k][1];
				if (nexti < n && nexti >= 0 && nextj < m && nextj >= 0)
				{
					if (minCost[nexti][nextj] > minCost[i][j] + grid[nexti][nextj])
					{
						minCost[nexti][nextj] = minCost[i][j] + grid[nexti][nextj];
						q.push(nexti * 1000000L + nextj);
					}
				}
			}
		}
		return minCost[n - 1][m - 1];
	}
};

int main()
{
	vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
	int ans = Solution().minimumObstacles(grid);
	cout << ans << endl;
	return 0;
}
