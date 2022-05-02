// https://leetcode-cn.com/problems/minimum-average-difference/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumAverageDifference(vector<int>& nums) {
		int n = nums.size();
		vector<long long> sum(n, 0);
		sum[0] = nums[0];
		for (int i = 1; i < n; ++i)
		{
			sum[i] = sum[i - 1] + nums[i];
		}
		int minIndex = -1;
		long long minAver = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			long long Aver = sum[i] / (i + 1);
			if ((n - i - 1) != 0)
			{
				Aver -= (sum[n - 1] - sum[i]) / (n - i - 1);
			}
			if (Aver < 0)
			{
				Aver = -Aver;
			}
			if (Aver < minAver)
			{
				minIndex = i;
				minAver = Aver;
			}
		}
		return minIndex;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums = {2, 5, 3, 9, 5, 3};
	int ans = s.minimumAverageDifference(nums);
	cout << ans << endl;
	return 0;
}
