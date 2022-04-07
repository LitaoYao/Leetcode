// https://leetcode-cn.com/problems/find-the-difference-of-two-arrays/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		int hash1[2001] = {0};
		int hash2[2001] = {0};
		int size1 = nums1.size();
		int size2 = nums2.size();
		for(int i = 0; i < size1; ++i)
		{
			hash1[nums1[i] + 1000] = 1;
		}
		for(int i = 0; i < size2; ++i)
		{
			hash2[nums2[i] + 1000] = 1;
		}
		vector<vector<int>> ans;
		ans.push_back(vector<int>());
		ans.push_back(vector<int>());
		for(int i = 0; i <= 2000; ++i)
		{
			if(hash1[i] == 1 && hash2[i] == 0)
			{
				ans[0].push_back(i - 1000);
			}
			if(hash1[i] == 0 && hash2[i] == 1)
			{
				ans[1].push_back(i - 1000);
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums1({1, 2, 3});
	vector<int> nums2({2, 4, 6});
	vector<vector<int>> ans = s.findDifference(nums1, nums2);
	int n = ans.size();
	for(int i = 0; i < n; ++i)
	{
		int m = ans[i].size();
		for(int  j = 0; j < m; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
