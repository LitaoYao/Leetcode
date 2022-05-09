// https://leetcode.cn/problems/multiply-strings/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int size1 = num1.size();
		int size2 = num2.size();
		int i1, i2, k;
		vector<int> ans(size1 + size2);
		for(int i = 0; i < size1; ++i)
		{
			for(int j = 0; j < size2; ++j)
			{
				i1 = size1 - i - 1;
				i2 = size2 - j - 1;
				k = i + j;
				ans[k] += (num1[i1] - '0') * (num2[i2] - '0');
			}
		}
		for(int i = 0; i < size1 + size2 - 1; ++i)
		{
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		string num = "";
		for(int i = size1 + size2 - 1; i >= 0; --i)
		{
			if(num.size() == 0 && ans[i] == 0)
			{
				continue;
			}
			num += ans[i] + '0';
		}
		if(num.size() == 0)
		{
			num = "0";
		}
		return num;
	}
};

int main()
{
	cout << Solution().multiply("1000023", "45");
	return 0;
}
