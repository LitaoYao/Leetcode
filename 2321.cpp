// https://leetcode.cn/problems/maximum-score-of-spliced-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<vector<long long>> dp1(n, vector<long long>(3, 0));
		vector<vector<long long>> dp2(n, vector<long long>(3, 0));
		for (int i = 0; i < 3; ++i)
		{
			dp1[0][i] = nums1[0];
			dp2[0][i] = nums2[0];
		}
		for (int i = 1; i < n; ++i)
		{
			dp1[i][0] = dp1[i - 1][0] + nums1[i];
			dp1[i][1] = max(dp1[i - 1][0], dp1[i - 1][1]) + nums2[i];
			dp1[i][2] = max(dp1[i - 1][1], dp1[i - 1][2]) + nums1[i];
			dp2[i][0] = dp2[i - 1][0] + nums2[i];
			dp2[i][1] = max(dp2[i - 1][0], dp2[i - 1][1]) + nums1[i];
			dp2[i][2] = max(dp2[i - 1][1], dp2[i - 1][2]) + nums2[i];
		}
		long long ans = 0;
		for (int i = 0; i < 3; ++i)
		{
			ans = max(ans, dp1[n - 1][i]);
			ans = max(ans, dp2[n - 1][i]);
		}
		return ans;
	}
};

int main()
{
	vector<int> nums1 = {20, 40, 20, 70, 30};
	vector<int> nums2 = {50, 20, 50, 40, 20};
	int ans = Solution().maximumsSplicedArray(nums1, nums2);
	cout << ans << endl;
	return 0;
}

