// https://leetcode.cn/problems/maximum-total-beauty-of-the-gardens/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
		sort(flowers.begin(), flowers.end());
		int n = flowers.size();
		if (flowers[0] >= target)
		{
			return (long long)n * full;
		}
		vector<long long> needs = vector<long long>(n, 0);
		for (int i = 1; i < n; ++i)
		{
			needs[i] = needs[i - 1] + (flowers[i] - flowers[i - 1]) * i;
		}
		vector<long long> uses = vector<long long>(n + 1, 0);
		long long sum = 0;
		int K = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			int tmp = max(0, target - flowers[i]);
			if (sum + tmp > newFlowers)
			{
				break;
			}
			sum += tmp;
			uses[++K] = sum;
		}
		long long ans = 0;
		for (long long k = 0; k <= K; ++k)
		{
			long long leftFlowers = newFlowers - uses[k];
			int left = 0, right = n - k - 1;
			while (left < right)
			{
				int mid = (left + right) >> 1;
				if (needs[mid] <= leftFlowers)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			if (needs[left] > leftFlowers)
			{
				--left;
			}
			int index = left;
			long long extra = (leftFlowers - needs[index]) / (index + 1);
			long long minFlowers = flowers[index] + extra;
			if (minFlowers >= target)
			{
				minFlowers = target - 1;
			}
			if (right < 0)
			{
				minFlowers = 0;
			}
			long long tmp = k * full + minFlowers * partial;
			if (ans < tmp)
			{
				ans = tmp;
			}
		}
		return ans;
	}
};
int main()
{
	/*
	   [1,3,1,1]
	   7
	   6
	   12
	   1
	   [2,4,5,3]
	   10
	   5
	   2
	   6
	*/
	Solution s = Solution();
	vector<int> flowers = {1, 3, 1, 1};
	long long newFlowers = 7;
	int target = 6;
	int full = 12;
	int partial = 1;
	long long ans = s.maximumBeauty(flowers, newFlowers, target, full, partial);
	cout << ans << endl;
	return 0;
}
