// https://leetcode-cn.com/problems/find-the-winner-of-the-circular-game/
#include <iostream>
using namespace std;

class Solution {
public:
	int findTheWinner(int n, int k) {
		if (n == 1)
		{
			return 1;
		}
		int last = findTheWinner(n - 1, k);
		return (k + last - 1) % n + 1;
	}
};

int main()
{
	Solution s = Solution();
	int n = 5;
	int k = 2;
	int ans = s.findTheWinner(n, k);
	cout << ans << endl;
	return 0;
}
