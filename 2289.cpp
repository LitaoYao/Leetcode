// https://leetcode.cn/problems/steps-to-make-array-non-decreasing/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	int totalSteps(vector<int>& nums) {
		stack<int> s;
		s.push(0);
		int n = nums.size();
		vector<int> counts(n, 0);
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] >= nums[s.top()])
			{
				bool has = false;
				int count = 0;
				while (s.size() > 1 && nums[i] >= nums[s.top()])
				{
					count = max(count, counts[s.top()]);
					has = true;
					s.pop();
				}
				if (has)
				{
					counts[s.top()] = max(counts[s.top()], count) + 1;
				}
			}
			while (!s.empty() && nums[i] >= nums[s.top()])
			{
				s.pop();
			}
			s.push(i);
		}
		bool has = false;
		int count = 0;
		while (s.size() > 1)
		{
			count = max(count, counts[s.top()]);
			has = true;
			s.pop();
		}
		if (has)
		{
			counts[s.top()] = max(counts[s.top()], count) + 1;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans = max(ans, counts[i]);
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
	int ans = Solution().totalSteps(nums);
	cout << ans << endl;
	return 0;
}
