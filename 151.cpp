// https://leetcode.cn/problems/reverse-words-in-a-string/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string link(string a, string b)
	{
		if(a == "")
		{
			return b;
		}
		if(b == "")
		{
			return a;
		}
		return a + " " + b;
	}
	string reverseWords1(string s) {
		string ans = "";
		string tmp = "";
		for(char c : s)
		{
			if(c == ' ')
			{
				ans = link(tmp, ans);
				tmp = "";
				continue;
			}
			tmp += c;
		}
		ans = link(tmp, ans);
		return ans;
	}

	// 原地法
	string reverseWords(string s) {
		int size = s.size();
		reverse(s.begin(), s.end());
		int start = 0, end = 0, next_start = 0;
		while(end < size)
		{
			start = next_start;
			end = start;
			while(end < size && s[end] == ' ')
			{
				 ++end;
			}
			next_start = end;
			while(end < size && s[end] != ' ')
			{
				 ++end;
			}
			reverse(s.begin() + start, s.begin() + end);
			next_start = start + end - next_start + 1;
		}
        int back = size - 1;
        while(s[back] == ' ')
        {
            --back;
        }
		s.erase(s.begin() + back + 1, s.end());
		return s;
	}
};

int main()
{
	string s = "hello world!";
	cout << Solution().reverseWords(s);
	return 0;
}
