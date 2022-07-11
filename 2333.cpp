// https://leetcode.cn/problems/minimum-sum-of-squared-difference/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
		int n = nums1.size();
		vector<long long> diff(n);
		for (int i = 0; i < n; ++i)
		{
			diff[i] = abs(nums1[i] - nums2[i]);
		}
		long long k = k1 + k2;
		sort(diff.begin(), diff.end());
		reverse(diff.begin(), diff.end());
		diff.push_back(0);
		int index = 0;
		// 先把前面的往下降，降到不能一起降为止
		for (int i = 1; i <= n; ++i)
		{
			long long x = diff[i - 1] - diff[i];
			if (x * i <= k)
			{
				k -= x * i;
				index = i;
			}
			else
			{
				break;
			}
		}
		// 前面index一起减k / (index + 1)
		for (int i = 0; i <= index; ++i)
		{
			diff[i] = diff[index];
			diff[i] -= k / (index + 1);
		}
		// 最后剩下k个减1
		k %= (index + 1);
		for (int i = 0; i < k; ++i)
		{
			diff[i] -= 1;
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (diff[i] > 0)
			{
				ans += diff[i] * diff[i];
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums1 = {1, 4, 10, 12};
	vector<int> nums2 = {5, 8, 6, 9};
	int k1 = 1;
	int k2 = 1;
	int ans = Solution().minSumSquareDiff(nums1, nums2, k1, k2);
	cout << ans << endl;
	return 0;
}

