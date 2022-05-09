// https://leetcode.cn/problems/count-prefixes-of-a-given-string/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countPrefixes(vector<string>& words, string s) {
		int ans = 0;
		for(size_t i = 0; i < words.size(); ++i)
		{
			bool prefix = true;
			if (words[i].size() > s.size())
			{
				prefix = false;
			}
			else
			{
				for(size_t j = 0; j < words[i].size(); ++j)
				{
					if (words[i][j] != s[j])
					{
						prefix = false;
					}
				} 
			}
			if (prefix)
			{
				++ans;
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<string> words = {"a", "b", "c", "ab", "bc", "abc"};
	string str = "abc";
	int ans = s.countPrefixes(words, str);
	cout << ans << endl;
	return 0;
}
