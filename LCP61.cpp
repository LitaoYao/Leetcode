// https://leetcode.cn/problems/6CE719/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
		int n = temperatureA.size();
		vector<int> a(n, 0);
		vector<int> b(n, 0);
		for (int i = 0; i < n - 1; ++i)
		{
			a[i] = temperatureA[i + 1] - temperatureA[i];
			if (a[i] > 0)
			{
				a[i] = 1;
			}
			else if (a[i] < 0)
			{
				a[i] = -1;
			}
			b[i] = temperatureB[i + 1] - temperatureB[i];
			if (b[i] > 0)
			{
				b[i] = 1;
			}
			else if (b[i] < 0)
			{
				b[i] = -1;
			}
		}
		int ans = 0;
		int tmp = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			if (a[i] == b[i])
			{
				++tmp;
			}
			else
			{
				tmp = 0;
			}
			ans = max(ans, tmp);
		}
		return ans;
	}
};

int main()
{
	vector<int> temperatureA = {21, 18, 18, 18, 31};
	vector<int> temperatureB = {34, 32, 16, 16, 17};
	int ans = Solution().temperatureTrend(temperatureA, temperatureB);
	cout << ans << endl;
	return 0;
}
