// https://https://leetcode.cn/problems/largest-local-values-in-a-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> newGrid(n - 2, vector<int>(n - 2, 0));
		vector<vector<int>> ways = {
			{-1, -1}, {-1, 0}, {-1, 1},
			{0, -1}, {0, 0}, {0, 1},
			{1, -1}, {1, 0}, {1, 1}
		};
		for (int i = 0; i < n - 2; ++i)
		{
			for (int j = 0; j < n - 2; ++j)
			{
				for (int k = 0; k < 9; ++k)
				{
					int ii = (i + 1) + ways[k][0];
					int jj = (j + 1) + ways[k][1];
					newGrid[i][j] = max(newGrid[i][j], grid[ii][jj]);
				}
			}
		}
		return newGrid;
	}
};

int main()
{
	vector<vector<int>> grid = {
		{9, 9, 8, 1},
		{5, 6, 2, 6},
		{8, 2, 6, 4},
		{6, 2, 2, 2},
	};
	vector<vector<int>> ans = Solution().largestLocal(grid);
	for (auto row : ans)
	{
		for (auto line : row)
		{
			cout << line << " ";
		}
		cout << endl;
	}
	return 0;
}
