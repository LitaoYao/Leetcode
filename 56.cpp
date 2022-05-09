// https://leetcode.cn/problems/merge-intervals/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(
			intervals.begin(), 
			intervals.end(),
			[=](const vector<int>& a, const vector<int>& b){
				if(a[0] == b[0])
				{
					return a[1] < b[1];
				}
				return a[0] < b[0];
			}
		);
		int size = intervals.size();
		int ans_size = 0;
		for(int i = 0; i < size; ++i)
		{
			if(ans_size == 0)
			{
				ans.push_back(intervals[i]);
				ans_size += 1;
			}
			else
			{
				if(ans[ans_size - 1][1] >= intervals[i][0])
				{
					ans[ans_size - 1][1] = max(ans[ans_size - 1][1], intervals[i][1]);
				}
				else
				{
					ans.push_back(intervals[i]);
					ans_size += 1;
				}
			}
		}
		for(int i = 0; i < ans_size; ++i)
		{
			cout << ans[i][0] << " " << ans[i][1] << endl;
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> intervals;
	intervals.push_back({1, 3});
	intervals.push_back({2, 6});
	intervals.push_back({8, 10});
	intervals.push_back({15, 18});
	Solution().merge(intervals);
	return 0;
}
