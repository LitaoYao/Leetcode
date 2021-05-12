// https://leetcode-cn.com/problems/gray-code/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans = {0};
		int size = 1;
		int x = 1;
		for(int i = 1; i <= n; ++i)
		{
			ans.resize(size * 2);
			for(int j = 0; j < size; ++j)
			{
				ans[2 * size - j - 1] = (ans[j] | x);
			}
			x <<= 1;
			size = size * 2;
		}
		for(int i = 0; i < size; ++i)
		{
			cout << ans[i] << " ";
		}
		return ans;
	}
};

int main()
{
	Solution().grayCode(3);
	return 0;
}
