// https://leetcode-cn.com/problems/largest-number-after-digit-swaps-by-parity/
#include <iostream>
using namespace std;

class Solution {
public:
	int largestInteger(int num) {
		int nums[10] = {0};
		int digits[10] = {0};
		int index = 0;
		while(num != 0)
		{
			int x = num % 10;
			++nums[x];
			digits[index++] = x % 2;
			num /= 10;
		}
		int ans = 0;
		int start;
		for (int i = index - 1; i >= 0; --i)
		{
			if (digits[i] == 0)
			{
				start = 8;
			}
			else
			{
				start = 9;
			}
			for (int j = start; j >= 0; j -= 2)
			{
				if (nums[j] > 0)
				{
					ans = ans * 10 + j;
					--nums[j];
					break;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	int ans = s.largestInteger(1234);
	cout << ans << endl;
	return 0;
}
