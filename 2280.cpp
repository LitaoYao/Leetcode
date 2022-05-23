// https://leetcode.cn/problems/minimum-lines-to-represent-a-line-chart/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumLines(vector<vector<int>>& stockPrices) {
		int n = stockPrices.size();
		if (n < 2)
		{
			return 0;
		}
		sort(stockPrices.begin(), stockPrices.end());
		int ans = 1;
		for (int i = 1; i < n - 1; ++i)
		{
			long long x0 = stockPrices[i - 1][0];
			long long y0 = stockPrices[i - 1][1];
			long long x1 = stockPrices[i][0];
			long long y1 = stockPrices[i][1];
			long long x2 = stockPrices[i + 1][0];
			long long y2 = stockPrices[i + 1][1];
			if ((y1 - y0) * (x2 - x1) != (y2 - y1) * (x1 - x0))
			{
				++ans;
			}
		}
		return ans;
	}
};

int main()
{
	// stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
	vector<vector<int>> stockPrices = {{1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 2}, {8, 1}};
	int ans = Solution().minimumLines(stockPrices);
	cout << ans << endl;
	return 0;
}
