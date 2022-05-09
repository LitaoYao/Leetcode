// https://leetcode.cn/problems/minimize-result-by-adding-parentheses-to-expression/
#include <iostream>
using namespace std;

class Solution {
public:
	string minimizeResult(string expression) {
		int nums[2][20];
		long long prefix[2][20];
		long long suffix[2][20];
		memset(nums, 0, sizeof(nums));
		memset(prefix, 0, sizeof(nums));
		memset(suffix, 0, sizeof(nums));
		int index = 0;
		for (int i = 0; expression[i] != '\0'; ++i)
		{
			char c = expression[i];
			if (c == '+')
			{
				++index;
			}
			else
			{
				nums[index][++nums[index][0]] = c - '0';
			}
		}
		for (index = 0; index < 2; ++index)
		{
			prefix[index][0] = 1;
			int tmp = 0;
			for (int i = 1; i <= nums[index][0]; ++i)
			{
				tmp = tmp * 10 + nums[index][i];
				prefix[index][i] = tmp;
			}  
		}
		for (index = 0; index < 2; ++index)
		{
			suffix[index][nums[index][0] + 1] = 1;
			int tmp = 0;
			int ten = 1;
			for (int i = nums[index][0]; i >= 1; --i)
			{
				tmp = ten * nums[index][i] + tmp;
				suffix[index][i] = tmp;
				ten *= 10;
			}  
		}
		long long value = INT_MAX;
		int min_i = 0, min_j = 0;
		for (int i = 1; i <= nums[0][0]; ++i)
		{
			for (int j = 1; j <= nums[1][0]; ++j)
			{
				// cout << prefix[0][i - 1] << " * (" << suffix[0][i] << " + " << prefix[1][j] << ") * " << suffix[1][j + 1] << endl;
				long long tmp = prefix[0][i - 1] * (suffix[0][i] + prefix[1][j]) * suffix[1][j + 1];
				if (tmp < value)
				{
					value = tmp;
					min_i = i;
					min_j = j;
				}
			}
		}
		string ans = "";
		for(int i = 1; i < min_i; ++i)
		{
			ans = ans + char(nums[0][i] + '0');
		}
		ans += '(';

		for(int i = min_i; i <= nums[0][0]; ++i)
		{
			ans = ans + char(nums[0][i] + '0');
		}
		ans += '+';
		for(int i = 1; i <= min_j; ++i)
		{
			ans = ans + char(nums[1][i] + '0');
		}
		ans += ')';

		for(int i = min_j + 1; i <= nums[1][0]; ++i)
		{
			ans = ans + char(nums[1][i] + '0');
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	string ans = s.minimizeResult("999+999");
	cout << ans << endl;
	return 0;
}
