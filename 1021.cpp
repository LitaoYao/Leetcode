// https://leetcode.cn/problems/remove-outermost-parentheses
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string removeOuterParentheses(string s) {
		int stack = 0;
		string ans = "";
		for (char c : s)
		{
			if (c == '(')
			{
				if (stack > 0)
				{
					ans += c;
				}
				++stack;
			}
			else
			{
				--stack;
				if (stack > 0)
				{
					ans += c;
				}
			}
		}
		return ans;
	}
};

int main()
{
	string s = "(()())(())(()(()))";
	string ans = Solution().removeOuterParentheses(s);
	cout << ans << endl;
	return 0;
}
