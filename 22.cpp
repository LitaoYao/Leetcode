// https://leetcode.cn/problems/generate-parentheses/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void dfs(vector<string>& ans, string brackets, int left, int right, int n)
	{
		if(left == n && right == n)
		{
			ans.push_back(brackets);
			return;
		}
		if(left < n)
		{
			dfs(ans, brackets + "(", left + 1, right, n);
		}
		if(right < left)
		{
			dfs(ans, brackets + ")", left , right + 1, n);
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		dfs(ans, "", 0, 0, n);
		return ans;
	}
};

int main()
{
	Solution().generateParenthesis(3);
	return 0;
}
