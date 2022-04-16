// https://leetcode-cn.com/problems/WHnhjV/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
		int n = gem.size();
		int m = operations.size();
		for (int i = 0; i < m; ++i)
		{
			int x = operations[i][0];
			int y = operations[i][1];
			int num = gem[x] / 2;
			gem[x] -= num;
			gem[y] += num;
		}
		sort(gem.begin(), gem.end());
		return gem[n - 1] - gem[0];
	}
};

int main()
{
	Solution s = Solution();
	vector<int> gem = {3, 1, 2};
	vector<vector<int>> operations = {{0, 2}, {2, 1}, {2, 0}};
	cout << s.giveGem(gem, operations);
	return 0;
}
