// https://leetcode-cn.com/problems/reverse-integer/
#include <iostream>
using namespace std;

class Solution {
public:
	int reverse(int x)
	{
		int ans = 0;
		while (x != 0)
		{
			// The condition is equal to:
			// INT_MIN <= ans * 10 + x % 10 <= INT_MAX
			//
			// Prove:
			// INT_MAX = [INT_MAX / 10] * 10 + INT_MAX % 10
			// ans * 10 + x % 10 <= INT_MAX = [INT_MAX / 10] * 10 + INT_MAX % 10
			// => (ans - [INT_MAX / 10]) * 10 <= INT_MAX % 10 - x % 10
			// When ans > [INT_MAX / 10], it is impossible.
			// When ans == [INT_MAX / 10], INT_MAX % 10 > x % 10 (as x < 2 and INT_MAX % 10 == 7), it is always true.
			// When ans < [INT_MAX / 10], INT_MAX % 10 - x % 10 >= -10, so it is always true.
			// Then ans * 10 + x % 10 <= INT_MAX <=> ans <= [INT_MAX / 10]
			if (ans < INT_MIN / 10 || ans > INT_MAX / 10)
			{
				return 0;
			}
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		return ans;
	}
};

int main()
{
	/*
	 123
	 -123
	 120
	 0
	 10
	 -2147483648
	 -1463847412
	 2147483647
	 1463847412
	*/
	Solution s = Solution();
	int ans = s.reverse(123);
	cout << ans << endl;
	return 0;
}
