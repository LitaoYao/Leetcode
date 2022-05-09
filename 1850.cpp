// https://leetcode.cn/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/submissions/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string next(string num)
	{
		int size = num.size();
		int i = size - 1;
		while(i > 0 && num[i] <= num[i - 1])
		{
			i--;
		}
		reverse(num.begin() + i, num.end());
		for(int j = i; j < size; ++j)
		{
			if(num[j] > num[i - 1])
			{
				swap(num[i - 1], num[j]);
				break;
			}
		}
		return num;
	}
	int getMinSwaps(string num, int k) {
		string f_num = num;
		for(int i = 0; i < k; ++i)
		{
			f_num = next(f_num);
		}
		int size = num.size();
		int count = 0;
		for(int i = 0; i < size; ++i)
		{
			for(int j = i; j < size; ++j)
			{
				if(f_num[j] == num[i])
				{
					for(int k = j; k > i; --k)
					{
						f_num[k] = f_num[k - 1];
						++count;
					}
					f_num[i] = num[i];
					break;
				}
			}
		}
		return count;
	}
};
