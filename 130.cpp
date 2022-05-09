// https://leetcode.cn/problems/surrounded-regions/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>>& board, int x, int y)
	{
		if(board[x][y] != 'O')
		{
			return;
		}
		board[x][y] = 'Y';
		int n = board.size();
		int m = board[0].size();
		int way[5] = {0, -1, 0, 1, 0};
		int nx, ny;
		for(int i = 0; i < 4; ++i)
		{
			nx = x + way[i];
			ny = y + way[i + 1];
			if(0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				dfs(board, nx, ny);
			}
		}
	}
	void solve(vector<vector<char>>& board) {
		int n = board.size();
		int m = board[0].size();
		for(int i = 0; i < n; ++i)
		{
			dfs(board, i, 0);
			dfs(board, i, m - 1);
		}
		for(int i = 0; i < m; ++i)
		{
			dfs(board, 0, i);
			dfs(board, n - 1, i);
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(board[i][j] == 'Y')
				{
					board[i][j] = 'O';
				}
				else if(board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				cout << board[i][j] << " ";
			}
			cout <<endl;
		}
	}
};

int main()
{
	vector<vector<char>> board;
	board.push_back({'X', 'X', 'X', 'X'});
	board.push_back({'X', 'O', 'O', 'X'});
	board.push_back({'X', 'X', 'O', 'X'});
	board.push_back({'X', 'O', 'X', 'X'});
	Solution().solve(board);
	return 0;
}
