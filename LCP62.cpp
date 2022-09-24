// https://leetcode.cn/problems/D9PW8w/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	int transportationHub(vector<vector<int>>& path) {
		map<int, vector<int>> edges;
		map<int, vector<int>> reverseEdges;
		set<int> points;
		for (vector<int>& p : path)
		{
			edges[p[0]].push_back(p[1]);
			reverseEdges[p[1]].push_back(p[0]);
			points.insert(p[0]);
			points.insert(p[1]);
		}
		int root = -1;
		bool valid = true;
		for (int node : points)
		{
			if (!edges.count(node))
			{
				if (root == -1)
				{
					root = node;
				}
				else
				{
					valid = false;
					break;
				}
			}
		}
		if (!valid)
		{
			return -1;
		}
		points.erase(root);
		if (reverseEdges.count(root))
		{
			for (int next : reverseEdges[root])
			{
				points.erase(next);
			}
		}
		if (points.empty())
		{
			return root;
		}
		else
		{
			return -1;
		}
	}
};

int main()
{
	vector<vector<int>> path = {{0, 1}, {0, 3}, {1, 3}, {2, 0}, {2, 3}};
	int ans = Solution().transportationHub(path);
	cout << ans << endl;
	return 0;
}
