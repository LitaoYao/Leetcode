// https://leetcode-cn.com/problems/check-if-there-is-a-valid-parentheses-string-path/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool dfs(vector<vector<char>>& grid, vector<vector<map<int, int>>>& mem, int& n, int& m, int x, int y, int leftCount)
	{
		if (grid[x][y] == ')')
		{
			if (leftCount <= 0)
			{
				return false;
			}
			else
			{
				--leftCount;
			}
		}
		else
		{
			++leftCount;
		}
		if (x == n - 1 && y == m - 1)
		{
			return leftCount == 0;
		}
		if ((n - x - 1) + (m - y - 1) < leftCount)
		{
			mem[x][y][leftCount] = false;
			return false;
		}
		if (mem[x][y].count(leftCount))
		{
			return mem[x][y][leftCount];
		}
		if (x + 1 < n)
		{
			if (dfs(grid, mem, n, m, x + 1, y, leftCount))
			{
				return true;
			}
			else
			{ 
				mem[x][y][leftCount] = false;
			}
		}
		if (y + 1 < m)
		{
			if (dfs(grid, mem, n, m, x, y + 1, leftCount))
			{
				return true;
			}
			else
			{ 
				mem[x][y][leftCount] = false;
			}
		}
		return false;
	}
	bool hasValidPath(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<map<int, int>>> mem(n, vector<map<int, int>>(m, map<int, int>()));
		return dfs(grid, mem, n, m, 0, 0, 0);
	}
};

int main()
{
	Solution s = Solution();
	vector<vector<char>> grid = {
		{'(', '(', '('},
		{')', '(', ')'},
		{'(', '(', ')'},
		{'(', '(', ')'}
	};
	bool ans = s.hasValidPath(grid);
	cout << ans << endl;
	return 0;
}
