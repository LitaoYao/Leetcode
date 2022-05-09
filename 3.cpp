// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> position;
		int size = s.length();
		int start_pos = 0;
		int ans = 0;
		for(int i = 0; i < size; ++i)
		{
			if(position.find(s[i]) != position.end())
			{
				int last_pos = position[s[i]];
				if(last_pos >= start_pos)
				{
					start_pos = last_pos + 1;
				}
			}
			position[s[i]] = i;
			ans = max(ans, i - start_pos + 1);
		}
		return ans;
	}
};

int main()
{
	string s = "pwwkew";
	cout << Solution().lengthOfLongestSubstring(s) << endl;
	return 0;
}
