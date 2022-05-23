// https://leetcode.cn/problems/cut-off-trees-for-golf-event/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int ways[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	int bfs(vector<vector<int>>& forest, vector<int>& from, vector<int>& to)
	{
		int n = forest.size();
		int m = forest[0].size();
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		queue<int> q;
		vis[from[0]][from[1]] = true;
		q.push(from[0] * 100 + from[1]);
		int step = 0;
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				int now = q.front();
				q.pop();
				int x = now / 100;
				int y = now % 100;
				if (x == to[0] && y == to[1])
				{
					return step;
				}
				for (int i = 0; i < 4; ++i)
				{
					int nextX = x + ways[i][0];
					int nextY = y + ways[i][1];
					if (nextX == to[0] && nextY == to[1])
					{
						return step + 1;
					}
					if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
					{
						if (!vis[nextX][nextY] && forest[nextX][nextY] != 0)
						{
							vis[nextX][nextY] = true;
							q.push(nextX * 100 + nextY);
						}
					}
				}
			}
			++step;
		}
		return -1;
	}
    int cutOffTree(vector<vector<int>>& forest) {
		int n = forest.size();
		int m = forest[0].size();
		vector<vector<int>> paths;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (forest[i][j] > 1)
				{
					paths.push_back({forest[i][j], i, j});
				}
			}
		}
		sort(paths.begin(), paths.end());
		int pathSize = paths.size();
		vector<int> now = {0, 0};
		vector<int> next = {0, 0};
		int ans = 0;
		for (int i = 0; i < pathSize; ++i)
		{
			next[0] = paths[i][1];
			next[1] = paths[i][2];
			int step = bfs(forest, now, next);
			if (step >= 0)
			{
				ans += step;
				now = next;
			}
			else
			{
				ans = -1;
				break;
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> forest = {
		{2, 3, 4},
		{0, 0, 5},
		{8, 7, 6},
	};
	int ans = Solution().cutOffTree(forest);
	cout << ans << endl;
	return 0;
}
