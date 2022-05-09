// https://leetcode.cn/problems/nth-magical-number/
#include <iostream>
using namespace std;

class Solution {
public:
	int gcd(int A, int B) {
		if(B == 0){
			return A;
		}
		return gcd(B, A % B);

	}
	int nthMagicalNumber(int N, int A, int B) {
		long long lcm = A * B / gcd(A, B);
		long long factor_count = lcm / A + lcm / B - 1;
		long long left = 0;
		long long right = lcm;
		long long target = N % factor_count;
		long long mid = 0;
		long long common = 0;
		long long now_count = 0;
		long long a_mod = 0;
		long long b_mod = 0;
		while(left < right){
			mid = (left + right) >> 1;
			common = 0;
			if(mid % A == 0 && mid % B == 0) common = 1;
			now_count = mid / A + mid / B - common;
			if(now_count < target) left = mid + 1;
			else if(now_count > target) right = mid - 1;
			else break;
		}
		mid = (left + right) >> 1;
		a_mod = mid % A;
		b_mod = mid % B;
		mid -= min(a_mod, b_mod);
		return lcm * (N / factor_count) % 1000000007 + mid;
	}
};

int main()
{
	Solution s = Solution();
	cout << s.nthMagicalNumber(5, 2, 3);
	return 0;
}
