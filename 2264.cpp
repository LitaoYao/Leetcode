// https://leetcode-cn.com/problems/largest-3-same-digit-number-in-string/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string largestGoodInteger(string num) {
		int n = num.size();
		string ans = "";
		for (int i = 0; i < n - 2; ++i)
		{
			string tmp = num.substr(i, 3);
			if (tmp[0] == tmp[1] && tmp[1] == tmp[2])
			{
				if (ans == "" || ans < tmp)
				{
					ans = tmp;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	string num = "6777133339";
	string ans = s.largestGoodInteger(num);
	cout << ans << endl;
	return 0;
}
