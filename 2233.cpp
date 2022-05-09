// https://leetcode.cn/problems/maximum-product-after-k-increments/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		nums.push_back(INT_MAX);
		int n = nums.size();
		int index = 0;
		long long sum = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			long long diff = (long long)(nums[i + 1] - nums[i]) * (i + 1);
			index = i;
			if (sum + diff > k)
			{
				break;
			}
			sum += diff;
		}
		k -= sum;
		int extra = k / (index + 1);
		int left = k - (extra * (index + 1));
		for (int i = 0; i <= index; ++i)
		{
			nums[i] = nums[index] + extra;
			if (i < left)
			{
				nums[i] += 1;
			}
		}
		long long ans = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			ans = (ans * nums[i]) % 1000000007;
		}
		return ans;
	}
};

int main()
{
	/*
	   [0,4]
	   5
	   [6,3,3,2]
	   2
	   [24,5,64,53,26,38]
	   54
   */
	Solution s = Solution();
	vector<int> nums = {24, 5, 64, 53, 26, 38};
	int k = 54;
	int ans = s.maximumProduct(nums, k);
	// ans = 180820950
	cout << ans << endl;
	return 0;
}
