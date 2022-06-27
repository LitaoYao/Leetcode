// https://leetcode.cn/problems/check-if-matrix-is-x-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkXMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		for (int i = 0; i < n; ++i)
		{
			if (grid[i][i] == 0)
			{
				return false;
			}
			if (grid[i][n - i - 1] == 0)
			{
				return false;
			}
			grid[i][i] = 0;
			grid[i][n - i - 1] = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<int>> grid = {
		{2, 0, 0, 1},
		{0, 3, 1, 0},
		{0, 5, 2, 0},
		{4, 0, 0, 2},
	};
	bool ans = Solution().checkXMatrix(grid);
	cout << ans << endl;
	return 0;
}

