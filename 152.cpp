// https://leetcode.cn/problems/maximum-product-subarray/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp_min(size);
		vector<int> dp_max(size);
		dp_min[0] = dp_max[0] = nums[0];
		int ans = dp_max[0];
		for(int i = 1; i < size; ++i)
		{
			dp_min[i] = dp_max[i] = nums[i];
			int max_pre = dp_max[i - 1] * nums[i];
			int min_pre = dp_min[i - 1] * nums[i];
			dp_max[i] = max(dp_max[i], max(max_pre, min_pre));
			dp_min[i] = min(dp_min[i], min(max_pre, min_pre));
			ans = max(ans, dp_max[i]);
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {-2, 0, -1};
	cout << Solution().maxProduct(nums);
	return 0;
}
