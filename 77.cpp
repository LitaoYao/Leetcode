// https://leetcode.cn/problems/combinations/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void doCombine(vector<vector<int>>& ans, int n, int k, vector<int>& group, int index)
	{
		if(k == 0)
		{
			int size = group.size();
			for(int i = 0; i < size; ++i)
			{
				cout << group[i] << " ";
			}
			cout << endl;
			ans.push_back(group);
			return;
		}
		for(int i = index; i <= n; ++i)
		{
			group[k - 1] = i;
			doCombine(ans, n, k - 1, group, i + 1);
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		if(k == 0 || n < k)
		{
			return ans;
		}
		vector<int> group(k);
		doCombine(ans, n, k, group, 1);
		return ans;
	}
};

int main()
{
	Solution().combine(4, 2);
	return 0;
}
