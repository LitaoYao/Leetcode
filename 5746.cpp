// https://leetcode-cn.com/problems/minimum-distance-to-the-target-element/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMinDistance(vector<int>& nums, int target, int start) {
		int size = nums.size();
		int left = start;
		int right = start;
		while(left >= 0 || right < size)
		{
			if(left >= 0 && nums[left] == target)
			{
				return abs(left - start);
			}
			if(right < size && nums[right] == target)
			{
				return abs(right - start);
			}
			left--;
			right++;
		}
		return 0;
	}
};
