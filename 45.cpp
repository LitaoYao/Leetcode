// https://leetcode.cn/problems/jump-game-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int jump_dp(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size);
		dp[0] = 0;
		for(int i = 1; i < size; ++i)
		{
			dp[i] = INT_MAX;
			for(int j = 0; j < i; ++j)
			{
				if(j + nums[j] >= i)
				{
					dp[i] = min(dp[j] + 1, dp[i]);
				}
			}
		}
		return dp[size - 1];
	}

	int jump(vector<int>& nums){
		int size = nums.size();
		int pos = 0;
		int next_pos = 0;
		int step = 0;
		while(pos < size - 1)
		{
			if(pos + nums[pos] >= size - 1)
			{
				++step;
				break;
			}
			next_pos = pos + 1;
			for(int i = pos + 1; i <= pos + nums[pos] && i < size; ++i)
			{
				if(i + nums[i] >= next_pos + nums[next_pos])
				{
					next_pos = i;
				}
			}
			pos = next_pos;
			++step;
		}
		return step;
	}
};

int main()
{
	vector<int> nums = {2, 3, 1};
	cout << Solution().jump(nums);
	return 0;
}
