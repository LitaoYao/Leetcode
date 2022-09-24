// https://leetcode.cn/problems/EXvqDp/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int ways[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	int n, m;
	bool dfs(vector<string>& plate, int x, int y, int way, int step, int num)
	{
		if (step > num)
		{
			return false;
		}
		if (plate[x][y] == 'O')
		{
			return true;
		}
		if (plate[x][y] == 'E')
		{
			way = (way + 4 - 1) % 4;
		}
		if (plate[x][y] == 'W')
		{
			way = (way + 1) % 4;
		}
		int nextx = x + ways[way][0];
		int nexty = y + ways[way][1];
		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
		{
			return false;
		}
		return dfs(plate, nextx, nexty, way, step + 1, num);
	}
	vector<vector<int>> ballGame(int num, vector<string>& plate) {
		n = plate.size();
		m = plate[0].size();
		vector<vector<int>> ans;
		int x, y;
		for (int i = 1; i < n - 1; ++i)
		{
			x = i;
			y = 0;
			if (plate[x][y] == '.')
			{
				if (dfs(plate, x, y, 3, 0, num))
				{
					ans.push_back({x, y});
				}
			}
			y = m - 1;
			if (plate[x][y] == '.')
			{
				if (dfs(plate, x, y, 1, 0, num))
				{
					ans.push_back({x, y});
				}
			}
		}
		for (int i = 1; i < m - 1; ++i)
		{
			x = 0;
			y = i;
			if (plate[x][y] == '.')
			{
				if (dfs(plate, x, y, 2, 0, num))
				{
					ans.push_back({x, y});
				}
			}
			x = n - 1;
			if (plate[x][y] == '.')
			{
				if (dfs(plate, x, y, 0, 0, num))
				{
					ans.push_back({x, y});
				}
			}
		}
		return ans;
	}
};

int main()
{
	vector<string> plate = {".....", "..E..", ".WO..", "....."};
	int num = 5;
	vector<vector<int>> ans = Solution().ballGame(num, plate);
	for (vector<int>& in : ans)
	{
		cout << in[0] << "," << in[1] <<endl;
	}
	return 0;
}
