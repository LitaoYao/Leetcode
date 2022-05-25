// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		int n = p.size();
		vector<int> alphabet(27, 0);
		int index = 0;
		while (index < n)
		{
			int cnt = index + 1;
			alphabet[p[cnt - 1] - 'a'] = max(alphabet[p[cnt - 1] - 'a'], cnt - index);
			while (cnt < n && p[cnt] == (p[cnt - 1] - 'a' + 1) % 26 + 'a')
			{
				++cnt;
				alphabet[p[cnt - 1] - 'a'] = max(alphabet[p[cnt - 1] - 'a'], cnt - index);
			}
			index = cnt;
		}
		int ans = 0;
		for (int i = 0; i < 26; ++i)
		{
			ans += alphabet[i];
		}
		return ans;
	}
};

int main()
{
	string p = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	int ans = Solution().findSubstringInWraproundString(p);
	cout << ans << endl;
	return 0;
}
