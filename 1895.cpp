// https://leetcode-cn.com/problems/largest-magic-square/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<long long>> row_sum;
	vector<vector<long long>> col_sum;
	bool isMagicSquare(vector<vector<int>>& grid, int x, int y, int k)
	{
		long long sum = row_sum[x + k - 1][y];
		if(x > 0)
		{
			sum -= row_sum[x - 1][y];
		}
		long long tmp_sum = 0;
		for(int j = y; j < y + k; ++j)
		{
			tmp_sum = row_sum[x + k - 1][j];
			if(x > 0)
			{
				tmp_sum -= row_sum[x - 1][j];
			}
			if(tmp_sum != sum)
			{
				return false;
			}
		}
		for(int i = x; i < x + k; ++i)
		{
			tmp_sum = col_sum[i][y + k - 1];
			if(y > 0)
			{
				tmp_sum -= col_sum[i][y - 1];
			}
			if(tmp_sum != sum)
			{
				return false;
			}
		}
		tmp_sum = 0;
		for(int i = 0; i < k; ++i)
		{
			tmp_sum += grid[x + i][y + i];
		}
		if(tmp_sum != sum)
		{
			return false;
		}
		tmp_sum = 0;
		for(int i = 0; i < k; ++i)
		{
			tmp_sum += grid[x + i][y + k - i - 1];
		}
		if(tmp_sum != sum)
		{
			return false;
		}
		return true;
	}
	bool hasMagicSquare(vector<vector<int>>& grid, int k)
	{
		int n = grid.size();
		int m = grid[0].size();
		for(int i = 0; i <= n - k; ++i)
		{
			for(int j = 0; j <= m - k; ++j)
			{
				if(isMagicSquare(grid, i, j, k))
				{
					return true;
				}
			}
		}
		return false;
	}
	int largestMagicSquare(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		row_sum = vector<vector<long long>>(n, vector<long long>(m));
		col_sum = vector<vector<long long>>(n, vector<long long>(m));
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(i > 0)
				{
					row_sum[i][j] = row_sum[i - 1][j] + grid[i][j];
				}
				else
				{
					row_sum[i][j] = grid[i][j];
				}
				if(j > 0)
				{
					col_sum[i][j] = col_sum[i][j - 1] + grid[i][j];
				}
				else
				{
					col_sum[i][j] = grid[i][j];
				}
			}
		}
		for(int k = min(n, m); k >= 1; --k)
		{
			if(hasMagicSquare(grid, k))
			{
				return k;
			}
		}
		return 0;
	}
};
