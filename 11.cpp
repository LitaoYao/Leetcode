// https://leetcode.cn/problems/container-with-most-water/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int calcArea(const vector<int>& height, int l, int r)
	{
		return (r - l) * min(height[l], height[r]);
	}

	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int ans = 0;
		while(left <= right)
		{
			ans = max(ans, calcArea(height, left, right));
			if(height[left] < height[right])
			{
				++left;
			}
			else if(height[left] > height[right])
			{
				--right;
			}
			else
			{
				++left;
				--right;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> height = {2,3,4,5,18,17,6};
	cout << Solution().maxArea(height) << endl;
	return 0;
}
