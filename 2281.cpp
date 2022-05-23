// https://leetcode.cn/problems/minimum-lines-to-represent-a-line-chart/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int totalStrength(vector<int>& strength) {
		int mod = 1000000000 + 7;
		int n = strength.size();
		// 前缀和
		vector<long long> sum(n, 0);
		for (int i = 0; i < n; ++i)
		{
			sum[i] = strength[i];
			if (i > 0)
			{
				sum[i] += sum[i - 1];
			}
		}
		// 以下标i结尾的子序列和
		vector<long long> endSum(n, 0);
		endSum[0] = strength[0];
		for (long long i = 1; i < n; ++i)
		{
			endSum[i] = endSum[i - 1] + (strength[i] * (i + 1));
		}
		// 以下标i开始的子序列和
		vector<long long> startSum(n, 0);
		startSum[n - 1] = strength[n - 1];
		for (long long i = n - 2; i >= 0; --i)
		{
			startSum[i] = startSum[i + 1] + (strength[i] * (n - i));
		}
		// 严格大于下标i的值的最左侧下标 开区间
		vector<int> leftMinIndex(n, -1);
		for (int i = 1; i < n; ++i)
		{
			int leftIndex = i - 1;
			while(leftIndex >= 0 && strength[leftIndex] > strength[i])
			{
				leftIndex = leftMinIndex[leftIndex];
			}
			leftMinIndex[i] = leftIndex;
		}
		// 大于等于下标i的值的最右侧下标 开区间
		vector<int> rightMinIndex(n, n);
		for (int i = n - 2; i >= 0; --i)
		{
			int rightIndex = i + 1;
			while(rightIndex < n && strength[rightIndex] >= strength[i])
			{
				rightIndex = rightMinIndex[rightIndex];
			}
			rightMinIndex[i] = rightIndex;
		}
		long long ans = 0;
		for (long long i = 0; i < n; ++i)
		{
			long long leftIndex = leftMinIndex[i];
			long long rightIndex = rightMinIndex[i];
			long long leftSum = endSum[i];
			if (leftIndex >= 0)
			{
				leftSum -= endSum[leftIndex];
				leftSum -= (sum[i] - sum[leftIndex]) * (leftIndex + 1);
			}
			long long rightSum = 0;
			if (i < n - 1 && rightIndex > i + 1)
			{
				rightSum = startSum[i + 1];
				if (rightIndex < n)
				{
					rightSum -= startSum[rightIndex];
					rightSum -= (sum[rightIndex - 1] - sum[i]) * (n - rightIndex);
				}
			}
			leftSum %= mod;
			rightSum %= mod;
			// strength[i] * 包含下标i的leftIndex到rightIndex之间的所有子序列和
			ans += strength[i] * (leftSum * (rightIndex - i) % mod + rightSum * (i - leftIndex) % mod) % mod;
			ans %= mod;
		}
		return ans;
	}
};

int main()
{
	vector<int> strength = {1, 3, 1, 2};
	int ans = Solution().totalStrength(strength);
	cout << ans << endl;
	return 0;
}
