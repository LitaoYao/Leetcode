// https://leetcode-cn.com/problems/string-to-integer-atoi/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		int size = s.size();
		int sign = 0;
		long long res = 0;
		for(int i = 0; i < size; ++i)
		{
			if(sign == 0)
			{
				if(s[i] == ' ')
				{
					continue;
				}
				else if(s[i] == '+')
				{
					sign = 1;
					continue;
				}
				else if(s[i] == '-')
				{
					sign = -1;
					continue;
				}
				else if(s[i] >= '0' && s[i] <= '9')
				{
					res = s[i] - '0';
					sign = sign == 0 ? 1 : sign;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(s[i] >= '0' && s[i] <= '9')
				{
					res = res * 10 + s[i] - '0';
					if(res * sign > INT_MAX)
					{
						return INT_MAX;
					}
					if(res * sign < INT_MIN)
					{
						return INT_MIN;
					}
				}
				else
				{
					break;
				}
			}
		}
		return res * sign;
	}
};

int main()
{
	cout << Solution().myAtoi("words and 987") << endl;
	return 0;
}
