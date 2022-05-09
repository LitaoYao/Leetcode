// https://leetcode.cn/problems/escape-the-spreading-fire/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int maximumMinutes(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		queue<vector<int>> q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == 1)
				{
					q.push({i, j, 0});
				}
			}
		}
		int ways[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
		int maxTime = 0;
		while (!q.empty())
		{
			vector<int> now = q.front();
			q.pop();
			int x = now[0];
			int y = now[1];
			int step = now[2];
			maxTime = max(maxTime, step);
			for (int j = 0; j < 4; ++j)
			{
				int nextX = x + ways[j][0];
				int nextY = y + ways[j][1];
				if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
				{
					if (grid[nextX][nextY] == 0)
					{
						grid[nextX][nextY] = -(step + 1);
						q.push({nextX, nextY, step + 1});
					}
				}
			}
		}
		int l = 0, r = maxTime + 2;
		int ans = -1;
		while(l < r)
		{
			vector<vector<int>> vis(n);
			for (int i = 0; i < n; ++i)
			{
				vis[i] = vector<int>(m, 0);
			}
			int mid = (l + r) >> 1;
			bool reach = false;
			q = queue<vector<int>>();
			q.push({0, 0, mid});
			vis[0][0] = 1;
			while (!q.empty())
			{
				vector<int> now = q.front();
				q.pop();
				int x = now[0];
				int y = now[1];
				int step = now[2];
				if (x == n - 1 && y == m - 1)
				{
					reach = true;
					break;
				}
				for (int j = 0; j < 4; ++j)
				{
					int nextX = x + ways[j][0];
					int nextY = y + ways[j][1];
					if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
					{
						if (vis[nextX][nextY] != 0)
						{
							continue;
						}
						if (nextX == n - 1 && nextY == m - 1)
						{
							if (grid[nextX][nextY] == 0 || (grid[nextX][nextY] < 0 && (step + 1) <= -grid[nextX][nextY]))
							{
								vis[nextX][nextY] = 1;
								q.push({nextX, nextY, step + 1});
							}
						}
						else if (grid[nextX][nextY] == 0 || (grid[nextX][nextY] < 0 && (step + 1) < -grid[nextX][nextY]))
						{
							vis[nextX][nextY] = 1;
							q.push({nextX, nextY, step + 1});
						}
					}
				}
			}
			if (reach)
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		if (ans >= maxTime)
		{
			return 1000000000;
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<vector<int>> grid = {
		{0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 2, 1, 0},
		{0, 2, 0, 0, 1, 2, 0},
		{0, 0, 2, 2, 2, 0, 2},
		{0, 0, 0, 0, 0, 0, 0}
	};
	int ans = s.maximumMinutes(grid);
	cout << ans << endl;
	return 0;
}
