// https://leetcode.cn/problems/shortest-impossible-sequence-of-rolls/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int shortestSequence(vector<int>& rolls, int k) {
		int n = rolls.size();
		int ans = 0;
		set<int> counts;
		for (int i = 0; i < n; ++i)
		{
			counts.insert(rolls[i]);
			if (counts.size() == k)
			{
				++ans;
				counts.clear();
			}
		}
		return ans + 1;
	}
};

int main()
{
	vector<int> rolls = {4, 2, 1, 2, 3, 3, 2, 4, 1};
	int k = 4;
	int ans = Solution().shortestSequence(rolls, k);
	cout << ans << endl;
	return 0;
}
