// https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool large(string& a, string& b)
	{
		int n = a.size();
		for (int i = 0; i < n; ++i)
		{
			if (a[i] < b[i])
			{
				return false;
			}
			if (a[i] > b[i])
			{
				return true;
			}
		}
		return true;
	}

	string removeDigit(string number, char digit) {
		vector<string> all;
		int n = number.size();
		for (int i = 0; i < n; ++i)
		{
			if (number[i] == digit)
			{
				all.push_back(number.substr(0, i) + number.substr(i + 1, number.size() - i));
			}
		}
		int index = 0;
		int allSize = all.size();
		for (int i = 1; i < allSize; ++i)
		{
			if (large(all[i], all[index]))
			{
				index = i;
			}
		}
		return all[index];
	}
};

int main()
{
	Solution s = Solution();
	string number = "1231";
	char digit = '1';
	string ans = s.removeDigit(number, digit);
	cout << ans << endl;
	return 0;
}
