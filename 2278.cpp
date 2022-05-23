// https://leetcode.cn/problems/percentage-of-letter-in-string/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int percentageLetter(string s, char letter) {
		int count = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == letter)
			{
				count++;
			}
		}
		return count * 100 / n;
	}
};

int main()
{
	string s = "foobar";
	char letter = 'o';
	int ans = Solution().percentageLetter(s, letter);
	cout << ans << endl;
	return 0;
}
