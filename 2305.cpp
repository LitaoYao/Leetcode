// https://leetcode.cn/problems/fair-distribution-of-cookies/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:	
	void dfs(vector<int>& cookies, vector<int>& groups, int& ans, int k, int index)
	{
		int n = cookies.size();
		if (index == n)
		{
			int tmp = 0;
			for(int group : groups)
			{
				tmp = max(tmp, group);
			}
			ans = min(ans, tmp);
			return;
		}
		for (int i = 0; i < k; ++i)
		{
			if (groups[i] + cookies[index] >= ans)
			{
				continue;
			}
			groups[i] += cookies[index];
			dfs(cookies, groups, ans, k, index + 1);
			groups[i] -= cookies[index];
		}
	}
	int distributeCookies(vector<int>& cookies, int k) {
		vector<int> groups(k, 0);
		int ans = INT_MAX;
		dfs(cookies, groups, ans, k, 0);
		return ans;
	}
};

int main()
{
	vector<int> cookies = {8, 15, 10, 20, 8};
	int k = 2;
	int ans = Solution().distributeCookies(cookies, k);
	cout << ans << endl;
	return 0;
}

