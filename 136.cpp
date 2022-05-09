// https://leetcode.cn/problems/single-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for(int num : nums)
		{
			ans ^= num;
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {2, 3, 3, 2, 5};
	cout << Solution().singleNumber(nums);
	return 0;
}
