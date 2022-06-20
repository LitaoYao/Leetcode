// https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string greatestLetter(string s) {
		vector<int> index1(26, -1);
		vector<int> index2(26, -1);
		int n = s.size();
		for (int i = 0; i < n; ++i)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				if (index1[s[i] - 'a'] == -1)
				{
					index1[s[i] - 'a'] = i;
				}
			}
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				if (index2[s[i] - 'A'] == -1)
				{
					index2[s[i] - 'A'] = i;
				}
			}
		}
		string ans = "";
		for (int i = 25; i >= 0; --i)
		{
			if (index1[i] != -1 && index2[i] != -1)
			{
				ans += char('A' + i);
				break;
			}
		}
		return ans;
	}
};

int main()
{
	string s = "arRAzFif";
	string ans = Solution().greatestLetter(s);
	cout << ans << endl;
	return 0;
}

