// https://leetcode.cn/problems/apply-discount-to-prices/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isDigit(char c)
	{
		return '0' <= c && c <= '9';
	}
	string double2str(double x)
	{
		long long num = ((long long)(x * 1000) + 5) / 10;
		if (num == 0)
		{
			return "0.00";
		}
		string numStr = "";
		string preStr = "";
		if (num < 100)
		{
			preStr = "0";
		}
		while (num != 0)
		{
			numStr = char(num % 10 + '0') + numStr;
			num /= 10;
			if (numStr.size() == 2)
			{
				numStr = "." + numStr;
			}
		}
		while (numStr.size() < 2)
		{
			numStr = "0" + numStr;
		}
		if (numStr.size() < 3)
		{
			numStr = "." + numStr;
		}
		numStr = preStr + numStr;
		return numStr;
	}
	string discountPrices(string sentence, int discount) {
		vector<vector<int>> indexs;
		vector<double> dollars;
		int n = sentence.size();
		for (int i = 0; i < n; ++i)
		{
			if (sentence[i] == '$' && (i == 0 || sentence[i - 1] == ' '))
			{
				int j = i + 1;
				long long dollar = 0;
				while (j < n && isDigit(sentence[j]))
				{
					dollar = dollar * 10 + sentence[j] - '0';
					++j;
				}
				if (j < n && sentence[j] != ' ')
				{
					dollar = 0;
				}
				if (dollar)
				{
					indexs.push_back({i, j - 1});
					dollars.push_back(dollar * (100 - discount) / 100.0);
				}
				i = j - 1;
			}
		}
		string ans = "";
		int nowDollarIndex = 0;
		int dollarSize = dollars.size();
		for (int i = 0; i < n; ++i)
		{
			if (nowDollarIndex < dollarSize && i == indexs[nowDollarIndex][0])
			{
				i = indexs[nowDollarIndex][1];
				ans += "$" + double2str(dollars[nowDollarIndex]);
				++nowDollarIndex;
			}
			else
			{
				ans += sentence[i];
			}
		}
		return ans;
	}
};

int main()
{
	string sentence = "there are $1 $2 and 5$ candies in the shop";
	int discount = 50;
	string ans = Solution().discountPrices(sentence, discount);
	cout << ans << endl;
	return 0;
}
