// https://leetcode.cn/problems/number-of-excellent-pairs/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	int countOne(long long x)
	{
		int ans = 0;
		while (x != 0)
		{
			if ((x & 1) == 1)
			{
				++ans;
			}
			x >>= 1;
		}
		return ans;
	}
	long long countExcellentPairs(vector<int>& nums, int k) {
		// 其实原题等价于找到所有数对，使得数对的1的位数之和大于等于k
		set<int> numSet; // 去重
		map<int, long long> oneSet; // key：1的位数，value：1的位数为key的数的个数
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (!numSet.count(nums[i]))
			{
				numSet.insert(nums[i]);
				int one = countOne(nums[i]);
				oneSet[one]++;
			}
		}
		vector<int> oneList; // 1的位数的数组，用于二分查找
		for (auto& one : oneSet)
		{
			oneList.push_back(one.first);
		}
		long long ans = 0;
		int m = oneList.size();
		vector<long long> sum(m, 0);
		sum[0] = oneSet[oneList[0]];
		for (int i = 1; i < m; ++i)
		{
			sum[i] = sum[i - 1] + oneSet[oneList[i]];
		}
		for (int i = 0; i < m; ++i)
		{
			int x = oneList[i];
			int y = k - x;
			if (y <= x)
			{
				// 自身就可以达成优质数对，直接算后缀和+自身对即可
				ans += (oneSet[oneList[i]]) * (oneSet[oneList[i]]);
				ans += oneSet[oneList[i]] * (sum[m - 1] - sum[i]) * 2;
				continue;
			}
			auto iter = lower_bound(oneList.begin(), oneList.end(), y);
			if (iter == oneList.end())
			{
				continue;
			}
			int index = (int)(iter - oneList.begin());
			ans += oneSet[oneList[i]] * (sum[m - 1] - sum[index] + oneSet[oneList[index]]) * 2;
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {1, 2, 3, 1};
	int k = 3;
	long long ans = Solution().countExcellentPairs(nums, k);
	cout << ans << endl;
	return 0;
}
