// https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isCovered(vector<vector<int>>& ranges, int left, int right) {
		for(int i = left; i <= right; ++i)
		{
			bool cover = false;
			for(int j = 0; j < ranges.size(); ++j)
			{
				if(ranges[j][0] <= i && i <= ranges[j][1])
				{
					cover = true;
					break;
				}
			}
			if(!cover)
			{
				return false;
			}
		}
		return true;
	}
};
