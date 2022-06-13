// https://leetcode.cn/problems/strong-password-checker-ii/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool strongPasswordCheckerII(string password) {
		int passwordSize = password.size();
		if(passwordSize < 8)
		{
			return false;
		}
		int smallCount = 0;
		int bigCount = 0;
		int numCount = 0;
		int specialCount = 0;
		string specialStr = "!@#$%^&*()-+";
		for (char c : password)
		{
			if (c >= 'a' && c <= 'z')
			{
				smallCount += 1;
				continue;
			}
			if (c >= 'A' && c <= 'Z')
			{
				bigCount += 1;
				continue;
			}
			if (c >= '0' && c <= '9')
			{
				numCount += 1;
				continue;
			}
			for (char s : specialStr)
			{
				if (c == s)
				{
					specialCount += 1;
					break;
				}
			}
		}
		if (smallCount == 0)
		{
			return false;
		}
		if (bigCount == 0)
		{
			return false;
		}
		if (numCount == 0)
		{
			return false;
		}
		if (specialCount == 0)
		{
			return false;
		}
		char last = password[0];
		for (int i = 1; i < passwordSize; ++i)
		{
			if (last == password[i])
			{
				return false;
			}
			last = password[i];
		}
		return true;
	}
};

int main()
{
	string password = "IloveLe3tcode!";
	bool ans = Solution().strongPasswordCheckerII(password);
	cout << ans << endl;
	return 0;
}
