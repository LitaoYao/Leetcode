// https://leetcode-cn.com/problems/UEcfPD/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

	int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
		int n = cookbooks.size();
		queue<vector<int>> q;
		vector<int> elem(5 + 3);
		elem[0] = -1;
		elem[1] = 0;
		elem[2] = 0;
		for (int i = 0; i < 5; ++i)
		{
			elem[i + 3] = materials[i];
		}
		int ans = -1;
		q.push(elem);
		while (!q.empty())
		{
			vector<int> now = q.front();
			q.pop();
			if (now[2] >= limit)
			{
				ans = max(ans, now[1]);
			}
			int index = now[0];
			int x = now[1];
			int y = now[2];
			vector<int> next;
			for (int i = index + 1; i < n; ++i)
			{
				bool can = true;
				for (int j = 0; j < 5; ++j)
				{
					if (cookbooks[i][j] > now[j + 3])
					{
						can = false;
						break;
					}
				}
				if (can)
				{
					next = now;
					for (int j = 0; j < 5; ++j)
					{
						next[j + 3] = now[j + 3] - cookbooks[i][j];
					}
					next[0] = i;
					next[1] = x + attribute[i][0];
					next[2] = y + attribute[i][1];
					q.push(next);
				}
				next = now;
				next[0] = i;
				q.push(next);
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> materials = {3, 2, 4, 1, 2};
	vector<vector<int>> cookbooks = {{1, 1, 0, 1, 2}, {2, 1, 4, 0, 0}, {3, 2, 4, 1, 0}};
	vector<vector<int>> attribute = {{3, 2}, {2, 4}, {7, 6}};
	int limit = 5;
	cout << s.perfectMenu(materials, cookbooks, attribute, limit);
	return 0;
}
