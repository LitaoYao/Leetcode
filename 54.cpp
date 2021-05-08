// https://leetcode-cn.com/problems/spiral-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<bool>> vis(n);
		for(int i = 0; i < n; ++i)
		{
			vis[i] = vector<bool>(m);
			for(int j = 0; j < m; ++j)
			{
				vis[i][j] = false;
			}
		}
		int i = 0;
		int j = 0;
		int way = 0;
		while(true)
		{
			cout << matrix[i][j] << " ";
			vis[i][j] = true;
			ans.push_back(matrix[i][j]);
			if(way == 0)
			{
				++j;
				if(j >= m || vis[i][j])
				{
					--j;
					++i;
					way = (way + 1) % 4;
				}
			}
			else if(way == 1)
			{
				++i;
				if(i >= n || vis[i][j])
				{
					--i;
					--j;
					way = (way + 1) % 4;
				}
			}
			else if(way == 2)
			{
				--j;
				if(j < 0 || vis[i][j])
				{
					++j;
					--i;
					way = (way + 1) % 4;
				}
			}
			else if(way == 3)
			{
				--i;
				if(i < 0 || vis[i][j])
				{
					++i;
					++j;
					way = (way + 1) % 4;
				}
			}
			if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
			{
				break;
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> matrix;
	matrix.push_back({1, 2, 3, 4});
	matrix.push_back({5, 6, 7, 8});
	matrix.push_back({9, 10, 11, 12});
	Solution().spiralOrder(matrix);
	return 0;
}
