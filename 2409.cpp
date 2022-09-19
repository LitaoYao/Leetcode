// https://leetcode.cn/problems/count-days-spent-together/
#include <iostream>
using namespace std;

class Solution {
public:
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int calcDay(string timeStr)
	{
		int month = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
		int day = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
		int ans = 0;
		for (int i = 1; i < month; ++i)
		{
			ans += days[i];
		}
		ans += day;
		return ans;
	}
	int calc(int a, int b, int c, int d)
	{
		if (b < c)
		{
			return 0;
		}
		if (b <= d)
		{
			return b - c + 1;
		}
		return d - c + 1;
	}
	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int aA = calcDay(arriveAlice);
		int lA = calcDay(leaveAlice);
		int aB = calcDay(arriveBob);
		int lB = calcDay(leaveBob);
		if (aA <= aB)
		{
			return calc(aA, lA, aB, lB);
		}
		else
		{
			return calc(aB, lB, aA, lA);
		}
	}
};

int main()
{
	string arriveAlice = "08-15";
	string leaveAlice = "08-18";
	string arriveBob = "08-16";
	string leaveBob = "08-19";
	int ans = Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);
	cout << ans << endl;
	return 0;
}
