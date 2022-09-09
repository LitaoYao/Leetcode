// https://leetcode.cn/problems/maximum-rows-covered-by-columns/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& mat, vector<int>& choose, int& ans, int count, int begin, int cols)
	{
		int n = mat.size();
		int m = mat[0].size();
		if (count == cols)
		{
			int tmp = 0;
			for (int i = 0; i < n; ++i)
			{
				bool valid = true;
				for (int j = 0; j < m; ++j)
				{
					if (mat[i][j] == 1 && choose[j] == 0)
					{
						valid = false;
						break;
					}
				}
				if (valid)
				{
					++tmp;
				}
			}
			ans = max(ans, tmp);
			return;
		}
		if (begin >= m)
		{
			return;
		}
		choose[begin] = 1;
		dfs(mat, choose, ans, count + 1, begin + 1, cols);
		choose[begin] = 0;
		dfs(mat, choose, ans, count, begin + 1, cols);
	}
	int maximumRows(vector<vector<int>>& mat, int cols) {
		int m = mat[0].size();
		int ans = 0;
		vector<int> choose(m, 0);
		dfs(mat, choose, ans, 0, 0, cols);
		return ans;
	}
};

int main()
{
	vector<vector<int>> mat = {
		{0, 0, 0},
		{1, 0, 1},
		{0, 1, 1},
		{0, 0, 1},
	};
	int cols = 2;
	int ans = Solution().maximumRows(mat, cols);
	cout << ans << endl;
	return 0;
}
