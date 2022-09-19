// https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	static const int N = 1e5;
	static const int LOGN = 18;
	long long st[N + 10][LOGN];
	long long Log2[N + 10];
	long long op(int a, int b)
	{
		return a | b;
	}
	void buildST(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			st[i][0] = nums[i];
		}
		for (int j = 1; j < LOGN; ++j)
		{
			int pj = (1 << (j - 1));
			for (int i = 0; i + pj < n; ++i)
			{
				st[i][j] = op(st[i][j - 1], st[i + pj][j - 1]);
			}
		}
	}
	void buildLog2(int n)
	{
		Log2[1] = 0;
		Log2[2] = 1;
		for (int i = 3; i <= n; ++i)
		{
			Log2[i] = Log2[i / 2] + 1;
		}
	}
	long long query(int l, int r)
	{
		int q = Log2[r - l + 1];
		return op(st[l][q], st[r - (1 << q) + 1][q]);
	}
	vector<int> smallestSubarrays(vector<int>& nums) {
		int n = nums.size();
		buildST(nums);
		buildLog2(n);
		vector<long long> B(n);
		B[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			B[i] = B[i + 1] | nums[i];
		}
		vector<int> ans(n, 0);
		for (int i = 0; i < n; ++i)
		{
			int l = i;
			int r = n - 1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				long long tmp = query(i, mid);
				if (tmp < B[i])
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
					ans[i] = mid - i + 1;
				}
			}
		}
		return ans;
	}
};

class Solution2 {
public:
	const int MAXP = 30;
	vector<int> smallestSubarrays(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(MAXP + 1, 0));
		for (int j = 0; j <= MAXP; ++j)
		{
			if ((nums[n - 1] >> j) & 1)
			{
				dp[n - 1][j] = n - 1;
			}
		}
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = 0; j <= MAXP; ++j)
			{
				dp[i][j] = dp[i + 1][j];
				if ((nums[i] >> j) & 1)
				{
					dp[i][j] = i;
				}
			}
		}
		vector<int> ans(n, 1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= MAXP; ++j)
			{
				ans[i] = max(ans[i], dp[i][j] - i + 1);
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {1, 0, 2, 1, 3};
	vector<int> ans = Solution().smallestSubarrays(nums);
	for (int x : ans)
	{
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
