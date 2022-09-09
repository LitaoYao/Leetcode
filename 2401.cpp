// https://leetcode.cn/problems/longest-nice-subarray/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestNiceSubarray(vector<int>& nums) {
		int n = nums.size();
		long long x = nums[0];
		int ans = 1;
		int index = 0;
		for (int i = 1; i < n; ++i)
		{
			if ((nums[i] & x) == 0)
			{
				x |= nums[i];
				ans = max(ans, i - index + 1);
			}
			else
			{
				while (index < i && (x & nums[i]) != 0)
				{
					x ^= nums[index];
					++index;
				}
				x |= nums[i];
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {1, 3, 8, 48, 10};
	int ans = Solution().longestNiceSubarray(nums);
	cout << ans << endl;
	return 0;
}
