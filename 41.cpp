// https://leetcode-cn.com/problems/first-missing-positive/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		nums.push_back(-1);
		for(int i = 0; i < n; ++i)
		{
			while(nums[i] > 0 && nums[i] <= n && nums[i] != i)
			{
				int j = nums[i];
				if(nums[i] == nums[j]) break;
				nums[i] = nums[j];
				nums[j] = j;
			}
		}
		for(int i = 1; i <= n; ++i)
		{
			if(nums[i] != i)
			{
				return i;
			}
		}
		return n + 1;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(1);
	Solution s;
	cout << s.firstMissingPositive(nums);
}
