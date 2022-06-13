// https://leetcode.cn/problems/naming-a-company/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	long long distinctNames(vector<string>& ideas) {
		vector<unordered_set<string>> groups(26, unordered_set<string>());
		int n = ideas.size();
		for (int i = 0; i < n; ++i)
		{
			int group = ideas[i][0] - 'a';
			groups[group].insert(ideas[i]);
		}
		long long ans = 0;
		vector<vector<long long>> mappings(26, vector<long long>(26, 0));
		for (string& a : ideas)
		{
			int i = a[0] - 'a';
			for (int j = 0; j < 26; ++j)
			{
				string newStr = a;
				newStr[0] = j + 'a';
				if (!groups[j].count(newStr))
				{
					mappings[i][j] += 1;
				}
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				ans += mappings[i][j] * mappings[j][i];
			}
		}
		return ans;
	}
};

int main()
{
	vector<string> ideas = {"coffee", "donuts", "time", "toffee"};
	long long ans = Solution().distinctNames(ideas);
	cout << ans << endl;
	return 0;
}

