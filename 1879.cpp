// https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = (1 << n) - 1; j >= 0; --j)
            {
                if(dp[j] == INT_MAX)
                {
                    continue;
                }
                for(int k = 0; k < n; ++k)
                {
                    if((j &(1 << k)) == 0)
                    {
                        int st = (j | (1 << k));
                        dp[st] = min(dp[st], dp[j] + (nums1[i] ^ nums2[k])); 
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};

int main()
{
	vector<int> nums1 = {1, 0, 3};
	vector<int> nums2 = {5, 3, 4};
	cout << Solution().minimumXORSum(nums1, nums2);
	return 0;
}
