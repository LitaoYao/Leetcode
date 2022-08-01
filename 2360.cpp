// https://leetcode.cn/problems/longest-cycle-in-a-graph/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	// 并查集算法
	int findRoot(vector<int>& fa, vector<int>& len, int x)
	{
		if (fa[x] != x)
		{
			int root = fa[x];
			fa[x] = findRoot(fa, len, root);
			len[x] += len[root];
		}
		return fa[x];
	}
	void merge(vector<int>& fa, vector<int>& len, int& ans, int a, int b)
	{
		int rootA = findRoot(fa, len, a);
		int rootB = findRoot(fa, len, b);
		if (rootA != rootB)
		{
			fa[rootA] = fa[rootB];
			len[a] = len[b] + 1;
		}
		else
		{
			ans = max(ans, len[a] + len[b] + 1);
		}
	}
	int longestCycle(vector<int>& edges) {
		int n = edges.size();
		vector<int> fa(n);
		vector<int> len(n);
		int ans = -1;
		for (int i = 0; i < n; ++i)
		{
			fa[i] = i;
			len[i] = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			if (edges[i] != -1)
			{
				merge(fa, len, ans, i, edges[i]);
			}
		}
		return ans;
	}
	// tarjan算法
	void tarjan(
		vector<int>& edges, vector<int>& dfn, vector<int>& low,
		vector<int>& colors, int& color, stack<int>& s, vector<int>& inStack,
		int node, int& cnt, int& ans
	)
	{
		dfn[node] = low[node] = ++cnt;
		s.push(node);
		inStack[node] = 1;
		int nextNode = edges[node];
		if (nextNode != -1)
		{
			if (dfn[nextNode] == -1)
			{
				tarjan(edges, dfn, low, colors, color, s, inStack, nextNode, cnt, ans);
				low[node] = min(low[nextNode], low[node]);
			}
			else if (inStack[nextNode])
			{
				low[node] = min(low[nextNode], low[node]);
			}
		}
		// 关键点（环入口）
		if (low[node] == dfn[node])
		{
			++color;
			int num = 0;
			while (!s.empty())
			{
				int x = s.top();
				s.pop();
				inStack[x] = 0;
				colors[x] = color;
				++num;
				if (x == node)
				{
					break;
				}
			}
			// 强联通分量大于1才是环
			if (num > 1)
			{
				ans = max(ans, num);
			}
		}
	}
	int longestCycleTarjan(vector<int>& edges) {
		int n = edges.size();
		vector<int> inStack(n, 0);
		vector<int> dfn(n, -1);
		vector<int> low(n, -1);
		vector<int> colors(n, -1);
		stack<int> s;
		int color = 0;
		int ans = -1;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (dfn[i] == -1)
			{
				tarjan(edges, dfn, low, colors, color, s, inStack, i, cnt, ans);
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> edges = {3, 3, 4, 2, 3};
	int ans = Solution().longestCycleTarjan(edges);
	cout << ans << endl;
	return 0;
}
