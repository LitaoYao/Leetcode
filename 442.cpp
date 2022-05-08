// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// Solution 1:
	/*
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;
		for (int i = 0; i < n; ++i)
		{
			while(nums[i] != i + 1 && nums[i] != -1)
			{
				int index = nums[i] - 1;
				if (nums[index] == nums[i])
				{
					ans.push_back(nums[i]);
					nums[i] = -1;
					break;
				}
				nums[i] = nums[index];
				nums[index] = index + 1;
			}
		}
		return ans;
	}
	*/

	// Solution 2:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;
		for (int i = 0; i < n; ++i)
		{
			int num = abs(nums[i]);
			if (nums[num - 1] < 0)
			{
				ans.push_back(num);
			}
			else
			{
				nums[num - 1] = -nums[num - 1];
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> ans = s.findDuplicates(nums);
	for (auto num : ans)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}
