// https://leetcode.cn/problems/longest-path-with-different-adjacent-characters/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
	void bfs(vector<vector<int>>& next, string& s, vector<vector<int>>& path, int root)
	{
		size_t n = path.size();
		vector<vector<int>> group(n);
		for (size_t i = 0; i < n; ++i)
		{
			group[i] = vector<int>();
		}
		queue<vector<int>> q;
		q.push({root, 0});
		int deep = 0;
		while (!q.empty())
		{
			vector<int> now = q.front();
			q.pop();
			deep = max(deep, now[1]);
			group[now[1]].push_back(now[0]);
			for (size_t i = 0; i < next[now[0]].size(); ++i)
			{
				q.push({next[now[0]][i], now[1] + 1});
			}
		}
		for (size_t i = 0; i < group[deep].size(); ++i)
		{
			int x = group[deep][i];
			path[x][0] = 1;
		}
		for (int d = deep - 1; d >= 0; --d)
		{
			for (size_t i = 0; i < group[d].size(); ++i)
			{
				int x = group[d][i];
				path[x][0] = 1;
				for(size_t j = 0; j < next[x].size(); ++j)
				{
					int y = next[x][j];
					if (s[x] == s[y])
					{
						continue;
					}
					int tmp = path[y][0] + 1;
					if (tmp >= path[x][0])
					{
						path[x][1] = path[x][0];
						path[x][0] = tmp;
					}
					else if (tmp >= path[x][1])
					{
						path[x][1] = tmp;
					}
				}
			}
		}
	}
	void dfs(vector<vector<int>>& next, string& s, vector<vector<int>>& path, int index)
	{
		path[index][0] = 1;
		for (size_t i = 0; i < next[index].size(); ++i)
		{
			dfs(next, s, path, next[index][i]);
			if (s[index] != s[next[index][i]])
			{
				int tmp = path[next[index][i]][0] + 1;
				if (tmp >= path[index][0])
				{
					path[index][1] = path[index][0];
					path[index][0] = tmp;
				}
				else if (tmp >= path[index][1])
				{
					path[index][1] = tmp;
				}
			}
		}
	}
	int longestPath(vector<int>& parent, string s) {
		size_t n = parent.size();
		vector<vector<int>> path(n);
		vector<vector<int>> next(n);
		for (size_t i = 0; i < n; ++i)
		{
			next[i] = vector<int>();
		}
		for (size_t i = 0; i < n; ++i)
		{
			path[i] = {0, 0};
			if (parent[i] != -1)
			{
				next[parent[i]].push_back(i);
			}
		}
		// bfs(next, s, path, 0);
		dfs(next, s, path, 0);
		int ans = 0;
		for(size_t i = 0; i < n; ++i)
		{
			ans = max(ans, path[i][0] + path[i][1] - 1);
			ans = max(ans, path[i][0]);
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> parent = {-1, 0, 0, 1, 1, 2};
	string str = "abacbe";
	int ans = s.longestPath(parent, str);
	cout << ans << endl;
	return 0;
}
