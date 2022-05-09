// https://leetcode.cn/problems/word-break/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool inDict(string s, unordered_set<string>& word_unordered_set)
	{
		return word_unordered_set.find(s) != word_unordered_set.end();
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		int size = s.size();
		vector<bool> dp(size, false);
		unordered_set<int> valid_indexs;
		unordered_set<string> word_unordered_set;
		for(string s : wordDict)
		{
			word_unordered_set.insert(s);
		}
		for(int i = 0; i < size; ++i)
		{
			dp[i] = inDict(s.substr(0, i + 1), word_unordered_set);
			if(dp[i])
			{
				valid_indexs.insert(i);
				continue;
			}
			for(int index : valid_indexs)
			{
				if(inDict(s.substr(index + 1, i - index), word_unordered_set))
				{
					dp[i] = true;
					valid_indexs.insert(i);
					break;
				}
			}
		}
		return dp[size - 1];
	}
};

int main()
{
	string s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	cout << Solution().wordBreak(s, wordDict);
	return 0;
}
