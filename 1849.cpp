// https://leetcode.cn/problems/splitting-a-string-into-descending-consecutive-values/submissions/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool dfs(string s, int cnt, int count, unsigned long long now_num)
	{
		int s_size = s.size();
		unsigned long long last_num = 0;
		if(count == 0)
		{
			for(int j = cnt; j < s_size; ++j)
			{
				last_num = last_num * 10 + s[j] - '0';
			}
			if(now_num - 1 != last_num)
				return false;
			return true;
		}
		for(int i = cnt; i < s_size - 1; ++i)
		{
			last_num = 0;
			for(int j = cnt; j <= i; ++j)
			{
				last_num = last_num * 10 + s[j] - '0';
			}
			if(now_num != -1 && now_num - 1 != last_num)
			{
				continue;
			}
			if(dfs(s, i + 1, count - 1, last_num))
			{
				return true;
			}
		}
		return false;
	}
	
	bool splitString(string s) {
		int size = s.size();
		for(int i = 1; i <= size; ++i)
		{
			if(dfs(s, 0, i, -1))
			{
				return true;
			}
		}
		return false;
	}
};
