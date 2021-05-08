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
		if(n == 1)
		{
			return x;
		}
		double ans = 1;
		double tmp = x;
		long long i = 1;
		while(i <= n)
		{
			if(i & n)
			{
				ans *= tmp;
			}
			tmp *= tmp;
			i <<= 1;
		}
		return ans;
	}
};

int main()
{
	cout << Solution().myPow(0.00001, 2147483647);
	return 0;
}
