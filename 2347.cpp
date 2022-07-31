// https://leetcode.cn/problems/best-poker-hand/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string bestHand(vector<int>& ranks, vector<char>& suits) {
		int n = ranks.size();
		vector<int> counts(14, 0);
		for (int i = 0; i < n; ++i)
		{
			counts[ranks[i]]++;
		}
		bool valid = true;
		for (int i = 1; i < n; ++i)
		{
			if (suits[i] != suits[0])
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			return "Flush";
		}
		valid = false;
		for (int i = 1; i <= 13; ++i)
		{
			if (counts[i] >= 3)
			{
				valid = true;
				break;
			}
		}
		if (valid)
		{
			return "Three of a Kind";
		}
		valid = false;
		for (int i = 1; i <= 13; ++i)
		{
			if (counts[i] >= 2)
			{
				valid = true;
				break;
			}
		}
		if (valid)
		{
			return "Pair";
		}
		return "High Card";
	}
};

int main()
{
	vector<int> ranks = {4, 4, 2, 4, 4};
	vector<char> suits = {'d', 'a', 'a', 'b', 'c'};
	string ans = Solution().bestHand(ranks, suits);
	cout << ans << endl;
	return 0;
}
