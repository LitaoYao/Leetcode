// https://leetcode.cn/problems/maximum-number-of-groups-entering-a-competition/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maximumGroups(vector<int>& grades) {
		int n = grades.size();
		sort(grades.begin(), grades.end());
		int ans = 0;
		long long lastScore = 0;
		int lastCount = 0;
		long long nowScore = 0;
		int nowCount = 0;
		for (int i = 0; i < n; ++i)
		{
			nowScore += grades[i];
			++nowCount;
			if (nowScore > lastScore && nowCount > lastCount)
			{
				++ans;
				lastScore = nowScore;
				lastCount = nowCount;
				nowScore = 0;
				nowCount = 0;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = {10, 6, 12, 7, 3, 5};
	int ans = Solution().maximumGroups(nums);
	cout << ans << endl;
	return 0;
}
