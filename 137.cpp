// https://leetcode.cn/problems/single-number-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		int x = 0;
		for(int i = 0; i < 32; ++i)
		{
			x = 0;
			for(int num : nums)
			{
				x += (num >> i) & 1;
			}
			if(x % 3)
			{
				ans |= 1 << i;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {2, 2, 3, 2};
	cout << Solution().singleNumber(nums);
	return 0;
}
