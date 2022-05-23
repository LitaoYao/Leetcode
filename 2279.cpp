// https://leetcode.cn/problems/maximum-bags-with-full-capacity-of-rocks/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		int n = capacity.size();
		vector<int> left(n);
		for (int i = 0; i < n; ++i)
		{
			left[i] = capacity[i] - rocks[i];
		}
		sort(left.begin(), left.end());
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] <= additionalRocks)
			{
				additionalRocks -= left[i];
				left[i] = 0;
			}
			if (left[i] == 0)
			{
				++ans;
			}
		}
		return ans;
	}
};

int main()
{
	// capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
	vector<int> capacity = {2, 3, 4, 5};
	vector<int> rocks = {1, 2, 4, 4};
	int additionalRocks = 2;
	int ans = Solution().maximumBags(capacity, rocks, additionalRocks);
	cout << ans << endl;
	return 0;
}
