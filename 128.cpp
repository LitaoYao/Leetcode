// https://leetcode-cn.com/problems/longest-consecutive-sequence/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> counts;
		int max_count = 0;
		int cur_count = 0;
		int left, right;
		for(const int& num : nums)
		{
			if(counts.count(num))
			{
				continue;
			}
			left = right = 0;
			if(counts.count(num - 1))
			{
				left = counts[num - 1];
			}
			if(counts.count(num + 1))
			{
				right = counts[num + 1];
			}
			cur_count = 1 + left + right;
			if(cur_count > max_count)
			{
				max_count = cur_count;
			}
			counts[num] = cur_count;
			counts[num - left] = cur_count;
			counts[num + right] = cur_count;
		}
		return max_count;
    }

    int longestConsecutive2(vector<int>& nums) {
		unordered_set<int> num_set;
		for(int num : nums)
		{
			num_set.insert(num);
		}
		int max_count = 0;
		int now_num = 0;
		int now_count = 0;
		for(const int& num : num_set)
		{
			if(num_set.find(num - 1) == num_set.end())
			{
				now_num = num;
				now_count = 1;
				while(num_set.find(now_num + 1) != num_set.end())
				{
					++now_num;
					++now_count;
				}
				max_count = max(max_count, now_count);
			}
		}
		return max_count;
    }
};

int main()
{
	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
	cout << Solution().longestConsecutive(nums);
	return 0;
}
