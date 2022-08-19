// https://leetcode.cn/problems/construct-smallest-number-from-di-string/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string smallestNumber(string pattern) {
		int n = pattern.size() + 1;
		vector<int> nums(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			nums[i] = i;
		}
		for (int i = n; i > 1;)
		{
			int k = i;
			while (k > 1 && pattern[k - 2] == 'D' && nums[k] > nums[k - 1])
			{
				swap(nums[k], nums[k - 1]);
				--k;
			}
			if (k == i)
			{
				--i;
			}
		}
		string ans = "";
		for (int i = 1; i <= n; ++i)
		{
			ans += '0' + nums[i];
		}
		return ans;
	}
};

int main()
{
	string pattern = "IIIDIDDD";
	string ans = Solution().smallestNumber(pattern);
	cout << ans << endl;
	return 0;
}
