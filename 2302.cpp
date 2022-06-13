// https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long countSubarrays(vector<int>& nums, long long k) {
		int n = nums.size();
		vector<long long> sum(n);
		for (int i = 0; i < n; ++i)
		{
			sum[i] = nums[i];
			if (i > 0)
			{
				sum[i] += sum[i - 1];
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int left = i;
			int right = n - 1;
			while (left < right)
			{
				int mid = (left + right) >> 1;
				if ((sum[mid] - sum[i] + nums[i]) * (mid - i + 1) >= k)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			while (left >= i && (sum[left] - sum[i] + nums[i]) * (left - i + 1) >= k)
			{
				--left;
			}
			if (left >= i)
			{
				ans += (left - i + 1);
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {2, 1, 4, 3, 5};
	long long k = 10;
	long long ans = Solution().countSubarrays(nums, k);
	cout << ans << endl;
	return 0;
}
