// https://leetcode-cn.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void pushSum(vector<int>& ans, int sum)
	{
		if(ans[0] == sum || ans[1] == sum || ans[2] == sum)
		{
			return;
		}
		for(int i = 0; i < 3; ++i)
		{
			if(sum <= ans[i])
			{
				return;
			}
			if(sum > ans[i])
			{
				ans[0] = sum;
				break;
			}
		}
		sort(ans.begin(), ans.end());
	}
	void getSum(vector<vector<int>>& grid, vector<int>& ans, int x, int y)
	{
		int n = grid.size();
		int m = grid[0].size();
		int sum;
		int max_row = min(min(m - y - 1, y) * 2, n - x - 1) / 2;
		int left;
		int right;
		for(int row = 0; row <= max_row; ++row)
		{
			sum = 0;
			for(int now_row = x; now_row <= x + row * 2; ++now_row)
			{
				if(now_row <= x + row)
				{
					left = y - (now_row - x);
					right = y + (now_row - x);
				}
				else
				{
					left = y - (x + row * 2 - now_row);
					right = y + (x + row * 2 - now_row);
				}
				if(left == right)
				{
					sum += grid[now_row][left];
				}
				else
				{
					sum += grid[now_row][left] + grid[now_row][right];
				}
			}
			pushSum(ans, sum);
		}
	}
	vector<int> getBiggestThree(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<int> ans(3, -1);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				getSum(grid, ans, i, j);
			}
		}
		sort(ans.begin(), ans.end());
		vector<int> real_ans;
		for(int i = 2; i >= 0; --i)
		{
			if(ans[i] != -1)
			{
				real_ans.push_back(ans[i]);
			}
		}
		return real_ans;
	}
};

int main()
{
	vector<vector<int>> grid;
	grid.push_back({3, 4, 5, 1, 3});
	grid.push_back({3, 3, 4, 2, 3});
	grid.push_back({20, 30, 200, 40, 10});
	grid.push_back({1, 5, 5, 4, 1});
	grid.push_back({4, 3, 2, 2, 5});
	Solution().getBiggestThree(grid);
	return 0;
}
