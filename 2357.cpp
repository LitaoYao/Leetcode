// https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		set<int> allNums;
		for (int x : nums)
		{
			if (x != 0)
			{
				allNums.insert(x);
			}
		}
		return allNums.size();
	}
};

int main()
{
	vector<int> nums = {1, 5, 0, 3, 5};
	int ans = Solution().minimumOperations(nums);
	cout << ans << endl;
	return 0;
}
