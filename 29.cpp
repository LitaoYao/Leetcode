// https://leetcode-cn.com/problems/divide-two-integers/
#include <iostream>
using namespace std;

class Solution {
public:
	long long opposite(long long x)
	{
		return ~x + 1;
	}

	long long add(long long a, long long b)
	{
		if(b == 0)
		{
			return a;
		}
		return add(a ^ b, (a & b) << 1);
	}

	long long minus(long long a, long long b)
	{
		return add(a, opposite(b));
	}

	long long multiple(long long a, long long b)
	{
		if(b == 0)
		{
			return 0;
		}
		int sign = 1;
		if(a < 0)
		{
			a = opposite(a);
			sign = opposite(sign);
		}
		if(b < 0)
		{
			b = opposite(b);
			sign = opposite(sign);
		}
		long long x = a;
		a = 0;
		while(b > 0)
		{
			if((b & 1) != 0)
			{
				a = add(a, x);
			}
			x <<= 1;
			b >>= 1;
		}
		if(sign < 0)
		{
			a = opposite(a);
		}
		return a;
	}

    int divide(int dividend, int divisor) {
		if(dividend == 0)
		{
			return 0;
		}
		long long a = dividend;
		long long b = divisor;
		int sign = 1;
		if(a < 0)
		{
			a = opposite(a);
			sign = opposite(sign);
		}
		if(b < 0)
		{
			b = opposite(b);
			sign = opposite(sign);
		}
		long long left = 1;
		long long right = a;
		long long mid;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			long long mul = multiple(b, mid);
			if(mul == a)
			{
				break;
			}
			else if(mul < a)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if(multiple(b, mid) > a)
		{
			mid--;
		}
		if(sign < 0)
		{
			mid = opposite(mid);
		}
		if(mid > INT_MAX)
		{
			mid = INT_MAX;
		}
		if(mid < INT_MIN)
		{
			mid = INT_MIN;
		}
		return mid;
    }
};

int main()
{
	long long a = -2147483648;
	long long b = 2;
	cout << "add: " << a << " + "  << b << " = " << Solution().add(a, b) << " real ans: " << a + b << endl;
	cout << "minus: " << a << " - "  << b << " = " << Solution().minus(a, b) << " real ans: " << a - b << endl;
	cout << "multiple: " << a << " * "  << b << " = " << Solution().multiple(a, b) << " real ans: " << a * b << endl;
	cout << "divide: " << a << " / "  << b << " = " << Solution().divide(a, b) << " real ans: " << a / b << endl;
	return 0;
}
