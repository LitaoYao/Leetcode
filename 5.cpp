// https://leetcode-cn.com/problems/longest-palindromic-substring/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getExpandLength(string s, int i, int right)
	{
		int size = s.size();
		int left = 2 * i - right;
		while(left > 0 && right < size && s[left] == s[right])
		{
			--left;
			++right;
		}
		return right - i - 1;
	}

    string longestPalindrome(string s) {
		string tmp_s = "#";
		int size = s.size();
		for(int i = 0; i < size; ++i)
		{
			tmp_s += s[i];
			tmp_s += "#";
		}
		vector<int> expand_lengths(2 * size + 1);
		int last_i = 0;
		int max_pos = 0;
		for(int i = 0; i < 2 * size + 1; ++i)
		{
			int expand_length = 1;
			if(i < last_i + expand_lengths[last_i])
			{
				int j = 2 * last_i - i;
				expand_length = min(last_i + expand_lengths[last_i] - i, expand_lengths[j]);
			}
			else
			{
				last_i = i;
			}
			expand_lengths[i] = getExpandLength(tmp_s, i, i + expand_length);
			if(expand_lengths[i] > expand_lengths[max_pos])
			{
				max_pos = i;
			}
		}
		string ans = "";
		if(max_pos == 0)
		{
			max_pos = 1;
		}
		for(int i = max_pos - expand_lengths[max_pos]; i <= max_pos + expand_lengths[max_pos]; ++i)
		{
			if(tmp_s[i] != '#')
			{
				ans += tmp_s[i];
			}
		}
		return ans;
    }
};

int main()
{
	string s = "";
	Solution solution = Solution();
	cout << solution.longestPalindrome(s) << endl;
	return 0;
}
