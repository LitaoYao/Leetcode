// https://leetcode.cn/problems/number-of-zero-filled-subarrays/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {
		int n = nums.size();
		long long count = 0;
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			count = 0;
			while (i < n && nums[i] == 0)
			{
				++i;
				++count;
			}
			ans += count * (count + 1) >> 1;
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
	long long ans = Solution().zeroFilledSubarray(nums);
	cout << ans << endl;
	return 0;
}
