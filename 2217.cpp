// https://leetcode-cn.com/problems/find-palindrome-with-fixed-length/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long connect(long long num, long long max_num, int cnt, int intLength)
	{
		if(num > max_num)
		{
			return -1;
		}
		vector<int> nums(cnt, 0);
		for(int i = 0; i < cnt; ++i)
		{
			nums[i] = num % 10;
			num /= 10;
		}
		int middle_zero_count = intLength - cnt * 2;
		long long ans = 0;
		// Fill in the head
		for(int i = 0; i < cnt; ++i)
		{
			ans = ans * 10 + nums[cnt - i - 1];
		}
		// Fill in the middle zeros
		for(int i = 0; i < middle_zero_count; ++i)
		{
			ans = ans * 10 + 0;
		}
		// Fill in the tail (notes: should consider the begin of index)
		int begin = 0;
		if(middle_zero_count < 0)
		{
			begin = 1;
		}
		for(int i = begin; i < cnt; ++i)
		{
			ans = ans * 10 + nums[i];
		}
		return ans;
	}
	vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
		int size = queries.size();
		vector<long long> ans(size);
		int cnt = (intLength + 1) / 2;
		long long max_num = 0;
		long long min_num = 1;
		for(int i = 0; i < cnt; ++i)
		{
			max_num = max_num * 10 + 9;
			min_num *= 10;
		}
		min_num /= 10;
		for(int i = 0; i < size; ++i)
		{
			ans[i] = connect(min_num + queries[i] - 1, max_num, cnt, intLength);
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums({1, 2, 3, 4, 5, 90});
	int intLength = 3;
	vector<long long> ans = s.kthPalindrome(nums, intLength);
	int size = ans.size();
	for(int i = 0; i < size; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
