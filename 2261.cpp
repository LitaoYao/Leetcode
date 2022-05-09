// https://leetcode.cn/problems/k-divisible-elements-subarrays/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int countDistinct(vector<int>& nums, int k, int p) {
		set<string> all;
		int n = nums.size();
		vector<int> pCount(n, 0);
		for (int i = 0; i < n; ++i)
		{
			int add = 0;
			if (nums[i] % p == 0)
			{
				add = 1;
			}
			if (i == 0)
			{
				pCount[i] = add;
			}
			else
			{
				pCount[i] = pCount[i - 1] + add;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			string tmp = "";
			for (int j = i; j < n; ++j)
			{
				tmp = tmp + char(nums[j] + '0');
				if (i == 0)
				{
					if (pCount[j] <= k)
					{
						all.insert(tmp);
					}
					else
					{
						break;
					}
				}
				else
				{
					if (pCount[j] - pCount[i - 1] <= k)
					{
						all.insert(tmp);
					}
					else
					{
						break;
					}
				}
			}
		}
		return all.size();
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums = {2, 3, 3, 2, 2};
	int k = 2;
	int p = 2;
	int ans = s.countDistinct(nums, k, p);
	cout << ans << endl;
	return 0;
}
