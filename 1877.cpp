// https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0;
		int left = 0;
		int right = nums.size() - 1;
		while(left < right)
		{
			ans = max(nums[left] + nums[right], ans);
			++left;
			--right;
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {3, 5, 4, 2, 4, 6};
	cout << Solution().minPairSum(nums);
	return 0;
}
