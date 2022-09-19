// https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
		int n = players.size();
		int m = trainers.size();
		sort(players.begin(), players.end());
		sort(trainers.begin(), trainers.end());
		int index = 0;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			while (index < m && trainers[index] < players[i])
			{
				++index;
			}
			if (index >= m)
			{
				break;
			}
			if (trainers[index] >= players[i])
			{
				++ans;
				++index;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> players = {4, 7, 9};
	vector<int> trainers = {8, 2, 5, 8};
	int ans = Solution().matchPlayersAndTrainers(players, trainers);
	cout << ans << endl;
	return 0;
}
