// https://leetcode.cn/problems/word-search/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool dfs(const vector<vector<char>>& board, const string word, vector<vector<bool>>& vis, const int i, const int j, const int index)
	{
		if(board[i][j] != word[index])
		{
			return false;
		}
		if(word[index + 1] == '\0')
		{
			return true;
		}
		vis[i][j] = true;
		int n = board.size();
		int m = board[0].size();
		int ways[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
		for(int w = 0; w < 4; ++w)
		{
			int nexti = i + ways[w][0];
			int nextj = j + ways[w][1];
			if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && !vis[nexti][nextj])
			{
				if(dfs(board, word, vis, nexti, nextj, index + 1))
				{
					return true;
				}
			}
		}
		vis[i][j] = false;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		int n = board.size();
		int m = board[0].size();
		vector<vector<bool>> vis(n);
		for(int i = 0; i < n; ++i)
		{
			vis[i] = vector<bool>(m);
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(dfs(board, word, vis, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<char>> board;
	board.push_back({'A', 'B', 'C', 'E'});
	board.push_back({'S', 'F', 'C', 'S'});
	board.push_back({'A', 'D', 'E', 'E'});
	cout << Solution().exist(board, "SEE");
	return 0;
}
