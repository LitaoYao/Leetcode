// https://leetcode-cn.com/problems/search-a-2d-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrixRow(vector<int>& row, int target)
	{
		int left = 0;
		int right = row.size() - 1;
		int mid = (left + right) >> 1;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			if(row[mid] == target)
			{
				return true;
			}
			else if(target > row[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int left = 0;
		int right = matrix.size() - 1;
		int mid = (left + right) >> 1;
		while(left <= right)
		{
			mid = (left + right) >> 1;
			if(matrix[mid][0] == target)
			{
				return true;
			}
			else if(target > matrix[mid][0])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if(matrix[mid][0] > target && mid > 0)
		{
			--mid;
		}
		return searchMatrixRow(matrix[mid], target);
	}
};

int main()
{
	vector<vector<int>> matrix;
	matrix.push_back({1, 3, 5, 7});
	matrix.push_back({10, 11, 16, 20});
	matrix.push_back({23, 30, 34, 60});
	cout << Solution().searchMatrix(matrix, 11);
	return 0;
}
