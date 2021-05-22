// https://leetcode-cn.com/problems/palindrome-partitioning/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

	bool isPalindrome(string s, int start, int end)
	{
		while(start < end)
		{
			if(s[start] != s[end])
			{
				return false;
			}
			++start;
			--end;
		}
		return true;
	}

	void dfs(vector<vector<string>>& ans, vector<string>& group, string s, int n, int index)
	{
		int size = s.size();
		if(n > size - index)
		{
			return;
		}
		if(n == 1)
		{
			if(isPalindrome(s, index, size - 1))
			{
				group.push_back(s.substr(index, size - index));
				for(string g : group)
				{
					cout << g << " ";
				}
				cout << endl;
				ans.push_back(group);
				group.pop_back();
			}
			return;
		}
		for(int i = index; i < size; ++i)
		{
			if(isPalindrome(s, index, i))
			{
				group.push_back(s.substr(index, i - index + 1));
				dfs(ans, group, s, n - 1, i + 1);
				group.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> group;
		int size = s.size();
		for(int i = 1; i <= size; ++i)
		{
			dfs(ans, group, s, i, 0);
		}
		return ans;
	}
};

int main()
{
	string s = "aab";
	Solution().partition(s);
	return 0;
}
