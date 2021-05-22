// https://leetcode-cn.com/problems/count-and-say/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string itos(int x)
	{
		string s = "";
		while(x != 0)
		{
			s = char('0' + x % 10) + s;
			x /= 10;
		}
		return s;
	}
	string countAndSay(int n) {
		string now = "1";
		string ans = now;
		char num = ' ';
		int count = 0;
		for(int i = 2; i <= n; ++i)
		{
			num = ' ';
			ans = "";
			for(int j = 0; now[j] != '\0'; ++j)
			{
				if(num != now[j])
				{
					if(num != ' ')
					{
						ans += itos(count) + num;
					}
					num = now[j];
					count = 1;
				}
				else
				{
					++count;
				}
			}
			if(num != ' ')
			{
				ans += itos(count) + num;
			}
			now = ans;
			cout << now << endl;
		}
		return ans;
	}
};

int main()
{
	cout << Solution().countAndSay(30);
	return 0;
}
