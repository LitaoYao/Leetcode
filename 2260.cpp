// https://leetcode-cn.com/problems/minimum-consecutive-cards-to-pick-up/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumCardPickup(vector<int>& cards) {
		vector<int> nums(1000005, INT_MAX);
		vector<int> numsIndex(1000005, -1);
		int n = cards.size();
		for (int i = 0; i < n; ++i)
		{
			if (numsIndex[cards[i]] != -1)
			{
				nums[cards[i]] = min(nums[cards[i]], i - numsIndex[cards[i]] + 1);
			}
			numsIndex[cards[i]] = i;
		}
		int ans = INT_MAX;
		for (int i = 0; i <= 1000000; ++i)
		{
			ans = min(ans, nums[i]);
		}
		if (ans == INT_MAX)
		{
			ans = -1;
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> cards = {3, 4, 2, 3, 4, 7};
	int ans = s.minimumCardPickup(cards);
	cout << ans << endl;
	return 0;
}
