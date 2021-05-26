// https://leetcode-cn.com/problems/longest-consecutive-sequence/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:

	// 方法一
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
			if(left)
			{
				counts[num - left] = cur_count;
			}
			if(right)
			{
				counts[num + right] = cur_count;
			}
		}
		return max_count;
    }

	// 方法二
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
			if(!num_set.count(num - 1))
			{
				now_num = num;
				now_count = 1;
				while(num_set.count(now_num + 1))
				{
					++now_num;
					++now_count;
				}
				max_count = max(max_count, now_count);
			}
		}
		return max_count;
    }

	// 方法三 并查集
	int find_fa(int num, unordered_map<int, int>& fa)
	{
		return fa.count(num) ? fa[num] = find_fa(fa[num], fa) : num;
	}

    int longestConsecutive3(vector<int>& nums) {
		unordered_map<int, int> fa;
		for(int num : nums)
		{
			fa[num] = num + 1;
		}
        int ans = 0;
		for(int num : nums)
		{
            int f = find_fa(num + 1, fa);
            ans = max(ans, f - num);
		}
		return ans;
    }
};

int main()
{
	vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
	cout << Solution().longestConsecutive3(nums);
	return 0;
}
