// https://leetcode-cn.com/problems/valid-sudoku/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidMiniSudoku(vector<vector<char>>& board, vector<int> indexs)
	{
		int counts[10] = {0};
		char chr;
		for(int i = 0; i < 9; ++i)
		{
			chr = board[indexs[i] / 10][indexs[i] % 10];
			if(chr != '.')
			{
				counts[chr - '0'] += 1;
				if(counts[chr - '0'] > 1)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> indexs(9);
		int count = 0;
		for(int i = 0; i < 9; ++i)
		{
			count = 0;
			for(int j = 0; j < 9; ++j)
			{
				indexs[count++] = i * 10 + j;
			}
			if(!isValidMiniSudoku(board, indexs))
			{
				return false;
			}
			count = 0;
			for(int j = 0; j < 9; ++j)
			{
				indexs[count++] = j * 10 + i;
			}
			if(!isValidMiniSudoku(board, indexs))
			{
				return false;
			}
		}
		for(int i = 0; i < 9; i += 3)
		{
			for(int j = 0; j < 9; j += 3)
			{
				count = 0;
				for(int k = i; k < i + 3; ++k)
				{
					for(int t = j; t < j + 3; ++t)
					{
						indexs[count++] = k * 10 + t;
					}
				}
				if(!isValidMiniSudoku(board, indexs))
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}
