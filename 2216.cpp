// https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minDeletion(vector<int>& nums) {
		int ans = 0;
		int size = nums.size();
		int cnt = 0;
		for(int i = 0; i < size - 1; ++i, ++cnt)
		{
			if(cnt % 2 == 0)
			{
				if(nums[i] == nums[i + 1])
				{
					cnt -= 1;
					ans += 1;
				}
			}
		}
		if((size - ans) % 2 != 0)
		{
			ans += 1;
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums({1, 1, 2, 2, 3, 3});
	cout << s.minDeletion(nums);
	return 0;
}
