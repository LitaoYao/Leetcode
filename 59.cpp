// https://leetcode-cn.com/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n);
		for(int i = 0; i < n; ++i)
		{
			matrix[i] = vector<int>(n);
		}
		int now_num = 0;
		for(int i = 0 ; i < (n + 1) / 2; ++i)
		{
			int len = n - i * 2 - 1;
			if(len == 0)
			{
				matrix[i][i] = ++now_num;
			}
			for(int j = i; j < i + len; ++j)
			{
				matrix[i][j] = ++now_num;
			}
			for(int k = i; k < i + len; ++k)
			{
				matrix[k][i + len] = ++now_num; 
			}
			for(int j = i + len; j > i; --j)
			{
				matrix[i + len][j] = ++now_num;
			}
			for(int k = i + len; k > i; --k)
			{
				matrix[k][i] = ++now_num;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "----------------------" << endl;
		return matrix;
	}
};

int main()
{
	Solution().generateMatrix(1);
	Solution().generateMatrix(2);
	Solution().generateMatrix(3);
	Solution().generateMatrix(4);
	Solution().generateMatrix(5);
	Solution().generateMatrix(6);
	return 0;
}
