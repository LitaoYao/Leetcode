// https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k/
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	int minimumNumbers(int num, int k) {
		if (num == 0)
		{
			return 0;
		}
		int x = num % 10;
		int count = 1;
		int nowNum = k;
		int end = k;
		set<int> reach;
		while (end != x && !reach.count(end))
		{
			reach.insert(end);
			++count;
			nowNum += k;
			end = nowNum % 10;
		}
		if (end == x && nowNum <= num)
		{
			return count;
		}
		else
		{
			return -1;
		}
	}
};

int main()
{
	int num = 58;
	int k = 9;
	int ans = Solution().minimumNumbers(num, k);
	cout << ans << endl;
	return 0;
}

