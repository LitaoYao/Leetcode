// https://leetcode.cn/problems/find-the-student-that-will-replace-the-chalk/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int chalkReplacer(vector<int>& chalk, int k) {
		long long sum = 0;
		for(int c : chalk)
		{
			sum += c;
		}
		k %= sum;
		for(int i = 0; i < chalk.size(); ++i)
		{
			if(k < chalk[i])
			{
				return i;
			}
			k -= chalk[i];
		}
		return 0;
	}
};
