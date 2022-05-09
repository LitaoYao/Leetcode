// https://leetcode.cn/problems/maximum-trailing-zeros-in-a-cornered-path/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void getTwoAndFive(int x, vector<int>& counts)
	{
		while(x % 2 == 0)
		{
			++counts[0];
			x /= 2;
		}
		while(x % 5 == 0)
		{
			++counts[1];
			x /= 5;
		}
	}
	int maxTrailingZeros(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<vector<int>>> verticals(n + 1);
		vector<vector<vector<int>>> horizontals(n + 1);
		for (int i = 0; i <= n; ++i)
		{
			verticals[i] = vector<vector<int>>(m + 1);
			horizontals[i] = vector<vector<int>>(m + 1);
			for (int j = 0; j <= m; ++j)
			{
				verticals[i][j] = {0, 0};
				horizontals[i][j] = {0, 0};
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				vector<int> counts = {0, 0};
				getTwoAndFive(grid[i - 1][j - 1], counts);
				for (int k = 0 ; k < 2; ++k)
				{
					verticals[i][j][k] = verticals[i - 1][j][k] + counts[k];
					horizontals[i][j][k] = horizontals[i][j - 1][k] + counts[k];
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				vector<int> tmp = {0, 0};
				for (int k = 0; k < 2; ++k)
				{
					tmp[k] = verticals[i - 1][j][k] + horizontals[i][j][k];
				}
				ans = max(ans, min(tmp[0], tmp[1]));
				for (int k = 0; k < 2; ++k)
				{
					tmp[k] = verticals[i][j][k] + (horizontals[i][m][k] - horizontals[i][j][k]);
				}
				ans = max(ans, min(tmp[0], tmp[1]));
				for (int k = 0; k < 2; ++k)
				{
					tmp[k] = (verticals[n][j][k] - verticals[i][j][k]) + horizontals[i][j][k];
				}
				ans = max(ans, min(tmp[0], tmp[1]));
				for (int k = 0; k < 2; ++k)
				{
					tmp[k] = (verticals[n][j][k] - verticals[i][j][k]) + (horizontals[i][m][k] - horizontals[i][j - 1][k]);
				}
				ans = max(ans, min(tmp[0], tmp[1]));
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	
	vector<vector<int>> grids = {
		{23, 17, 15, 3, 20},
		{8, 1, 20, 27, 11},
		{9, 4, 6, 2, 21},
		{40, 9, 1, 10, 6},
		{22, 7, 4, 5, 3}
	};
	int ans = s.maxTrailingZeros(grids);
	cout << ans << endl;
	return 0;
}
