// https://leetcode.cn/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int k = (n + m + 1) >> 1;
		int left1 = -1, right1 = n;
		int left2 = -1, right2 = m;
		int mid1;
		int mid2;
		while (left1 + 1 < right1 || left2 + 1 < right2)
		{
			mid1 = (left1 + right1) >> 1;
			mid2 = (left2 + right2) >> 1;
			if (mid1 + mid2 + 2 < k)
			{
				if (mid2 < 0 || mid2 == m)
				{
					left1 = mid1;
				}
				else if (mid1 < 0 || mid1 == n)
				{
					left2 = mid2;
				}
				else if ((nums1[mid1] < nums2[mid2] && (left1 + 1) < right1) || ((left2 + 1) >= right2))
				{
					left1 = mid1;
				}
				else
				{
					left2 = mid2;
				}
			}
			else if (mid1 + mid2 + 2 > k)
			{
				if (mid2 < 0 || mid2 == m)
				{
					right1 = mid1;
				}
				else if (mid1 < 0 || mid1 == n)
				{
					right2 = mid2;
				}
				else if ((nums1[mid1] > nums2[mid2] && (left1 + 1) < right1) || ((left2 + 1) >= right2))
				{
					right1 = mid1;
				}
				else
				{
					right2 = mid2;
				}
			}
			else
			{
				if (mid2 < 0 || mid2 == m)
				{
					break;
				}
				else if (mid1 < 0 || mid1 == n)
				{
					break;
				}
				else if ((nums1[mid1] < nums2[mid2] && (left1 + 1) < right1) || ((left2 + 1) >= right2))
				{
					left1 = mid1;
				}
				else
				{
					left2 = mid2;
				}
			}
		}
		mid1 = (left1 + right1) >> 1;
		mid2 = (left2 + right2) >> 1;
		double x1, x2;
		if (mid2 == -1 || mid2 == m)
		{
			x1 = nums1[mid1];
		}
		else if (mid1 == -1 || mid1 == n)
		{
			x1 = nums2[mid2];
		}
		else
		{
			x1 = max(nums1[mid1], nums2[mid2]);
		}
		if ((n + m) % 2 != 0)
		{
			x2 = x1;
		}
		else
		{
			if (mid2 == m - 1)
			{
				x2 = nums1[mid1 + 1];
			}
			else if (mid1 == n - 1)
			{
				x2 = nums2[mid2 + 1];
			}
			else
			{
				x2 = min(nums1[mid1 + 1], nums2[mid2 + 1]);
			}
		}
		return (x1 + x2) / 2;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> nums1 = {1, 3};
	vector<int> nums2 = {2};
	cout << s.findMedianSortedArrays(nums1, nums2);
	return 0;
}
