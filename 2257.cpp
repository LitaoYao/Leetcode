// https://leetcode.cn/problems/count-unguarded-cells-in-the-grid/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		vector<vector<vector<int>>> grid(m);
		for (int i = 0; i < m; ++i)
		{
			grid[i] = vector<vector<int>>(n);
			for (int j = 0; j < n; ++j)
			{
				grid[i][j] = {0, 0, 0, 0, 0};
			}
		}
		int wallsSize = walls.size();
		for (int i = 0; i < wallsSize; ++i)
		{
			grid[walls[i][0]][walls[i][1]][0] = 1;
		}
		queue<vector<int>> q;
		int guardsSize = guards.size();
		int ways[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
		for (int i = 0; i < guardsSize; ++i)
		{
			grid[guards[i][0]][guards[i][1]][0] = 2;
			for (int j = 0; j < 4; ++j)
			{
				q.push({guards[i][0], guards[i][1], j});
			}
		}
		while (!q.empty())
		{
			vector<int> now = q.front();
			q.pop();
			int x = now[0];
			int y = now[1];
			int w = now[2];
			grid[x][y][w + 1] = 1;
			int nextX = x + ways[w][0];
			int nextY = y + ways[w][1];
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				if (grid[nextX][nextY][0] != 0)
				{
					continue;
				}
				if (grid[nextX][nextY][w + 1] != 0)
				{
					continue;
				}
				q.push({nextX, nextY, w});
			}
		}
		int ans = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j][0] == 0)
				{
					for (int w = 0; w < 4; ++w)
					{
						if (grid[i][j][w + 1] != 0)
						{
							grid[i][j][0] = 3;
							break;
						}
					}
				}
				// cout << grid[i][j][0] << " ";
				if (grid[i][j][0] == 0)
				{
					++ans;
				}
			}
			// cout << endl;
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	int m = 4;
	int n = 6;
	vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
	vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
	int ans = s.countUnguarded(m, n, guards, walls);
	cout << ans << endl;
	return 0;
}
