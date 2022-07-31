// https://leetcode.cn/problems/equal-row-and-column-pairs/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {
		int n = grid.size();
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				bool valid = true;
				for (int k = 0; k < n; ++k)
				{
					if (grid[i][k] != grid[k][j])
					{
						valid = false;
						break;
					}
				}
				if (valid)
				{
					++ans;
				}
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
	int ans = Solution().equalPairs(grid);
	cout << ans << endl;
	return 0;
}
