// https://leetcode.cn/problems/set-matrix-zeroes/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		bool row0 = false;
		for(int i = 0; i < n; ++i)
		{
			if(matrix[i][0] == 0)
			{
				row0 = true;
				break;
			}
		}
		bool col0 = false;
		for(int j = 0; j < m; ++j)
		{
			if(matrix[0][j] == 0)
			{
				col0 = true;
				break;
			}
		}
		for(int i = 1; i < n; ++i)
		{
			for(int j = 1; j < m; ++j)
			{
				if(matrix[i][j] == 0)
				{
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		for(int i = 1; i < n; ++i)
		{
			if(matrix[i][0] == 0)
			{
				for(int j = 1; j < m; ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for(int j = 1; j < m; ++j)
		{
			if(matrix[0][j] == 0)
			{
				for(int i = 1; i < n; ++i)
				{
					matrix[i][j] = 0;
				}
			}
		}
		if(row0)
		{
			for(int i = 0; i < n; ++i)
			{
				matrix[i][0] = 0;
			}
		}
		if(col0)
		{
			for(int j = 0; j < m; ++j)
			{
				matrix[0][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	vector<vector<int>> matrix;
	matrix.push_back({1, 1, 1});
	matrix.push_back({1, 0, 1});
	matrix.push_back({1, 1, 1});
	Solution().setZeroes(matrix);
	return 0;
}
