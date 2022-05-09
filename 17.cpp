// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	Solution()
	{
		char_map['2'] = "abc";
		char_map['3'] = "def";
		char_map['4'] = "ghi";
		char_map['5'] = "jkl";
		char_map['6'] = "mno";
		char_map['7'] = "pqrs";
		char_map['8'] = "tuv";
		char_map['9'] = "wxyz";
	}
	void dfs(string digits, int index, string tmp_ans, vector<string>& ans)
	{
		if(digits[index] == '\0' && tmp_ans.size() > 0)
		{
			ans.push_back(tmp_ans);
			return;
		}
		int size = char_map[digits[index]].size();
		for(int i = 0; i < size; ++i)
		{
			dfs(digits, index + 1, tmp_ans + char_map[digits[index]][i], ans);
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		dfs(digits, 0, "", ans);
		return ans;
	}
	unordered_map<char, string> char_map;
};

int main()
{
	Solution().letterCombinations("23");
	return 0;
}
