// https://leetcode.cn/problems/rotate-image/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate_ij(vector<vector<int>>& matrix, int i, int j)
	{
		int size = matrix.size();
		int len = size - i * 2 - 1;
		int next_i = j;
		int next_j = i + len;
		swap(matrix[i][j], matrix[next_i][next_j]);
		next_i = i + len;
		next_j = i + len - (j - i);
		swap(matrix[i][j], matrix[next_i][next_j]);
		next_i = i + len - (j - i);
		next_j = i;
		swap(matrix[i][j], matrix[next_i][next_j]);
	}
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		for(int i = 0; i < (size + 1) / 2; ++i)
		{
			for(int  j = i; j < size - i - 1; ++j)
			{
				rotate_ij(matrix, i, j);
			}
		}
		for(int i = 0; i < size; ++i)
		{
			for(int j = 0; j < size; ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	vector<vector<int>> matrix(4);
	matrix[0] = {5, 1, 9, 11};
	matrix[1] = {2, 4, 8, 10};
	matrix[2] = {13, 3, 6, 7};
	matrix[3] = {15, 14, 12, 16};
	Solution().rotate(matrix);
	return 0;
}
