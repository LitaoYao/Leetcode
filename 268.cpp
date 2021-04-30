// https://leetcode-cn.com/problems/missing-number/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int missingNumber(vector<int>& nums) {
			int size = nums.size();
			int i, j, temp;
			for(i = 0; i < size; ++i)
			{
				j = nums[i];
				while(i != j && j != -1 && j < size)
				{
					temp = nums[j];
					nums[j] = nums[i];
					nums[i] = temp;
					j = nums[i];
				}
			}
			for(i = 0; i < size; ++i)
			{
				if(nums[i] != i)
				{
					return i;
				}
			}
			return size;
		}
};
int main()
{
	Solution s = Solution();
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(6);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	cout << s.missingNumber(nums);
	return 0;
}
