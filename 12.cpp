// https://leetcode.cn/problems/integer-to-roman/
#include <iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string ans;
		string chars[7][2] = {
			{"M", "C"},
			{"D", "C"},
			{"C", "X"},
			{"L", "X"},
			{"X", "I"},
			{"V", "I"},
			{"I", ""},
		};
		int romans[7][2] = {
			{1000, 900},
			{500, 400},
			{100, 90},
			{50, 40},
			{10, 9},
			{5, 4},
			{1, 0}
		};
		int size= 7;
		for(int i = 0; i < size; ++i)
		{
			if(num >= romans[i][0])
			{
				int count = num / romans[i][0];
				for(int j = 0; j < count; ++j)
				{
					ans += chars[i][0];
				}
				num %= romans[i][0];
			}
			if(i < size - 1 && num >= romans[i][1])
			{
				ans += chars[i][1] + chars[i][0];
				num -= romans[i][1];
			}
		}
		return ans;
	}
};

int main()
{
	cout << Solution().intToRoman(1994) << endl;
	return 0;
}
