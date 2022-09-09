// https://leetcode.cn/problems/check-distances-between-same-letters/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkDistances(string s, vector<int>& distance) {
		int n = s.size();
		vector<int> indexs(26, -1);
		for (int i = 0; i < n; ++i)
		{
			int x = s[i] - 'a';
			if (indexs[x] != -1 && i - indexs[x] - 1 != distance[x])
			{
				return false;
			}
			indexs[x] = i;
		}
		return true;
	}
};

int main()
{
	string s = "abaccb";
	vector<int> distance = {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	bool ans = Solution().checkDistances(s, distance);
	cout << ans << endl;
	return 0;
}
