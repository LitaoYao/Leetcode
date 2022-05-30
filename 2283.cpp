// https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool digitCount(string num) {
		vector<int> counts(10, 0);
		for (char x : num)
		{
			counts[x - '0']++;
		}
		for (int i = 0 ;i < num.size(); ++i)
		{
			if (counts[i] != num[i] - '0')
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	string num = "1210";
	bool ans = Solution().digitCount(num);
	cout << ans << endl;
	return 0;
}
