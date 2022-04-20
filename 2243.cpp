// https://leetcode-cn.com/problems/calculate-digit-sum-of-a-string/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string num2str(int num)
	{
		if (num == 0)
		{
			return "0";
		}
		string str = "";
		while(num > 0)
		{
			str += num % 10 + '0';
			num /= 10;
		}
		reverse(str.begin(), str.end());
		return str;
	}
	string digitSum(string s, int k) {
		while(s.size() > (size_t)k)
		{
			string tmp = "";
			for (size_t i = 0; i < s.size(); i += k)
			{
				size_t begin = i;
				size_t end = i + k;
				int num = 0;
				for (size_t j = begin; j < end && j < s.size(); ++j)
				{
					num += s[j] - '0';
				}
				tmp += num2str(num);
			}
			s = tmp;
		}
		return s;
	}
};

int main()
{
	Solution s = Solution();
	string str = "11111222223";
	int k = 3;
	string ans = s.digitSum(str, k);
	cout << ans << endl;
	return 0;
}
