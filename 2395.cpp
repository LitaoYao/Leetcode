// https://leetcode.cn/problems/find-subarrays-with-equal-sum/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool findSubarrays(vector<int>& nums) {
		set<long long> counts;
		int n = nums.size();
		for(int i = 0; i < n - 1; ++i)
		{
			long long sum = nums[i] + nums[i + 1];
			if (counts.count(sum))
			{
				return true;
			}
			counts.insert(sum);
		}
		return false;
	}
};

int main()
{
	vector<int> nums = {4, 2, 4};
	bool ans = Solution().findSubarrays(nums);
	cout << ans << endl;
	return 0;
}
