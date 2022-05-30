// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int rearrangeCharacters(string s, string target) {
		vector<int> counts(27, 0);
		for (char c : s)
		{
			counts[c - 'a']++;
		}
		vector<int> counts2(27, 0);
		for (char c : target)
		{
			counts2[c - 'a']++;
		}
		int ans = -1;
		for (int i = 0; i < 26; ++i)
		{
			if (counts2[i])
			{
				if (ans == -1)
				{
					ans = counts[i] / counts2[i];
				}
				else
				{
					ans = min(ans, counts[i] / counts2[i]);
				}
			}
		}
		return ans;
	}
};

int main()
{
	string s = "ilovecodingonleetcode";
	string target = "code";
	int ans = Solution().rearrangeCharacters(s, target);
	cout << ans << endl;
	return 0;
}
