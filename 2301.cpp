// https://leetcode.cn/problems/match-substring-after-replacement/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getOrder(char x)
	{
		if (x >= 'a' && x <= 'z')
		{
			return x - 'a';
		}
		if (x >= 'A' && x <= 'Z')
		{
			return x - 'A' + 26;
		}
		return x - '0' + 26 + 26;
	}

	bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
		int allCharCount = 26 + 26 + 10;
		vector<vector<bool>> canChange(allCharCount, vector<bool>(allCharCount, false));
		for (int i = 0; i < allCharCount; ++i)
		{
			canChange[i][i] = true;
		}
		int mapSize = mappings.size();
		for (int i = 0; i < mapSize; ++i)
		{
			int oldOrder = getOrder(mappings[i][0]);
			int newOrder = getOrder(mappings[i][1]);
			canChange[oldOrder][newOrder] = true;
		}
		int sSize = s.size();
		int subSize = sub.size();
		vector<int> orderS(sSize);
		vector<int> orderSub(subSize);
		for (int i = 0; i < sSize; ++i)
		{
			orderS[i] = getOrder(s[i]);
		}
		for (int i = 0; i < subSize; ++i)
		{
			orderSub[i] = getOrder(sub[i]);
		}
		for (int i = 0; i < sSize - subSize + 1; ++i)
		{
			bool valid = true;
			for (int j = 0; j < subSize; ++j)
			{
				if (!canChange[orderSub[j]][orderS[i + j]])
				{
					valid = false;
					break;
				}
			}
			if (valid)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	string s = "fool3e7bar";
	string sub = "leet";
	vector<vector<char>> mappings = {{'e', '3'}, {'t', '7'}, {'t', '8'}};
	bool ans = Solution().matchReplacement(s, sub, mappings);
	cout << ans << endl;
	return 0;
}
