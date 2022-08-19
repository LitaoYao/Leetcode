// https://leetcode.cn/problems/node-with-highest-edge-score/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int edgeScore(vector<int>& edges) {
		int n = edges.size();
		vector<long long> scores(n, 0);
		for (int i = 0; i < n; ++i)
		{
			scores[edges[i]] += i;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (scores[i] > scores[ans])
			{
				ans = i;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> edges = {1, 0, 0, 0, 0, 7, 7, 5};
	int ans = Solution().edgeScore(edges);
	cout << ans << endl;
	return 0;
}
