// https://leetcode-cn.com/problems/jump-game/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int index = 0;
		int size = nums.size();
		int next_index = 0;
		while(index + nums[index] < size && nums[index] > 0)
		{
			next_index = index;
			for(int i = index + 1; i < size && i <= index + nums[index]; ++i)
			{
				if(i + nums[i] >= next_index + nums[next_index])
				{
					next_index = i;
				}
			}
			index = next_index;
		}
		return index + nums[index] >= size - 1;
	}
};

int main()
{
	vector<int> nums = {3, 2, 1, 0, 4};
	cout << Solution().canJump(nums);
	return 0;
}
