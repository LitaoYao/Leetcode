// https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		int n = spells.size();
		int m = potions.size();
		vector<int> ans(n);
		sort(potions.begin(), potions.end());
		for (int i = 0; i < n; ++i)
		{
			long long target = success / spells[i];
			if (target * spells[i] < success)
			{
				target += 1;
			}
			int index = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
			ans[i] = m - index;
		}
		return ans;
	}
};

int main()
{
	vector<int> spells = {5, 1, 3};
	vector<int> potions = {1, 2, 3, 4, 5};
	long long success = 7;
	vector<int> ans = Solution().successfulPairs(spells, potions, success);
	for (int x : ans)
	{
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
