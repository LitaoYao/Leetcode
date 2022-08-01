// https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void search(vector<int>& edges, int startNode, vector<int>& dist)
	{
		int n = edges.size();
		queue<int> q;
		for (int i = 0; i < n; ++i)
		{
			dist[i] = -1;
		}
		dist[startNode] = 0;
		q.push(startNode);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			if (edges[node] != -1 && dist[edges[node]] == -1)
			{
				dist[edges[node]] = dist[node] + 1;
				q.push(edges[node]);
			}
		}
	}
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		int n = edges.size();
		vector<int> dist1(n);
		vector<int> dist2(n);
		search(edges, node1, dist1);
		search(edges, node2, dist2);
		int minDist = -1;
		int node = -1;
		for (int i = 0; i < n; ++i)
		{
			if (dist1[i] != -1 && dist2[i] != -1)
			{
				int d = max(dist1[i], dist2[i]);
				if (minDist == -1 || minDist > d)
				{
					minDist = d;
					node = i;
				}
			}
		}
		return node;
	}
};

int main()
{
	vector<int> edges = {2, 2, 3, -1};
	int node1 = 0;
	int node2 = 1;
	int ans = Solution().closestMeetingNode(edges, node1, node2);
	cout << ans << endl;
	return 0;
}
