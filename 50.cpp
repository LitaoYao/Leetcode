// https://leetcode-cn.com/problems/powx-n/
#include <iostream>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		if(n < 0)
		{
			if(n == INT_MIN)
			{
				return 1 / (myPow(x, -(n + 1)) * x);
			}
			return 1 / myPow(x, -n);
		}
		if(n == 0)
		{
			return 1;
		}
		double ans = 1;
		double tmp = x;
		int i = 1;
		while(i <= n)
		{
			if(i & n)
			{
				ans *= tmp;
			}
			tmp *= tmp;
			if(i > (n >> 1))
			{
				break;
			}
			i <<= 1;
		}
		return ans;
	}
};

int main()
{
	cout << Solution().myPow(1.00000, -2147483648);
	return 0;
}
