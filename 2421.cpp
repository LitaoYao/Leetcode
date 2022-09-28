// https://leetcode.cn/problems/number-of-good-paths/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int findFa(vector<int>& fa, int x)
	{
		if (fa[x] != x)
		{
			fa[x] = findFa(fa, fa[x]);
		}
		return fa[x];
	}
	void addEdge(vector<vector<int>>& edges, int a, int b)
	{
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
		int n = vals.size();
		vector<vector<int>> myEdges(n);
		for (vector<int>& edge : edges)
		{
			addEdge(myEdges, edge[0], edge[1]);
		}
		int ans = n;
		vector<int> fa(n);
		vector<int> counts(n);
		vector<vector<int>> nodes(n, vector<int>(2));
		for (int i = 0; i < n; ++i)
		{
			nodes[i] = {vals[i], i};
			fa[i] = i;
			counts[i] = 1;
		}
		sort(nodes.begin(), nodes.end());
		for (int i = 0; i < n; ++i)
		{
			int a = nodes[i][1];
			int rootA = findFa(fa, a);
			for (int b : myEdges[a])
			{
				int rootB = findFa(fa, b);
				if (rootA == rootB || vals[rootB] > vals[rootA])
				{
					continue;
				}
				if (vals[rootB] == vals[rootA])
				{
					ans += counts[rootA] * counts[rootB];
					counts[rootA] += counts[rootB];
				}
				fa[rootB] = rootA;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> vals = {1, 3, 2, 1, 3};
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
	int ans = Solution().numberOfGoodPaths(vals, edges);
	cout << ans << endl;
	return 0;
}
