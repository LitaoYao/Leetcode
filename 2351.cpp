// https://leetcode.cn/problems/first-letter-to-appear-twice/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	char repeatedCharacter(string s) {
		map<char, int> counts;
		for (char c : s)
		{
			counts[c]++;
			if (counts[c] >= 2)
			{
				return c;
			}
		}
		return ' ';
	}
};

int main()
{
	string s = "abccbaacz";
	char ans = Solution().repeatedCharacter(s);
	cout << ans << endl;
	return 0;
}
