// https://leetcode-cn.com/problems/sudoku-solver/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class BlankHeap{
public:
	vector<int> heap;
	unordered_map<int, int> index_map;
	unordered_map<int, set<char>> blanks;
	bool empty()
	{
		return heap.size() <= 0;
	}
	bool get_blank(int ij, set<char>& blank)
	{
		if(blanks.find(ij) == blanks.end())
		{
			return false;
		}
		blank = blanks[ij];
		return true;
	}
	int top()
	{
		return heap[0];
	}
	bool min_cmp(const int& a, const int& b)
	{
		return blanks[a].size() < blanks[b].size();
	}
	void push(const int& ij, set<char>& blank)
	{
		blanks[ij] = blank;
		heap.push_back(ij);
		int index = heap.size() - 1;
		shift_up(index);
	}
	void pop()
	{
		int tail = heap.size() - 1;
		if(tail < 0)
		{
			return;
		}
		index_map.erase(heap[0]);
		blanks.erase(heap[0]);
		heap[0] = heap[tail];
		heap.pop_back();
		if(tail > 0)
		{
			shift_down(0);
		}
	}
	void modify(const int& ij, const set<char>& blank)
	{
		blanks[ij] = blank;
		int index = index_map[ij];
		index = shift_up(index);
		index = shift_down(index);
	}
	int shift_up(int index)
	{
		int tmp = heap[index];
		int ij;
		while(index > 0 && min_cmp(tmp, heap[(index - 1) >> 1]))
		{
			heap[index] = heap[(index - 1) >> 1];
			ij = heap[index];
			index_map[ij] = index;
			index = (index - 1) >> 1;
		}
		heap[index] = tmp;
		ij = heap[index];
		index_map[ij] = index;
		return index;
	}
	int shift_down(int index)
	{
		int size = heap.size();
		int left = index;
		int right = index;
		int child = index;
		int tmp = heap[index];
		int ij;
		while(2 * index + 1 < size)
		{
			left = 2 * index + 1;
			right = left + 1;
			child = left;
			if(right < size && min_cmp(heap[right], heap[left]))
			{
				child = right;
			}
			if(!min_cmp(tmp, heap[child]))
			{
				heap[index] = heap[child];
				ij = heap[index];
				index_map[ij] = index;
				index = child;
			}
			else
			{
				break;
			}
		}
		heap[index] = tmp;
		ij = heap[index];
		index_map[ij] = index;
		return child;
	}
};

class Solution {
public:
	bool solveSudokuDFS(vector<vector<char>>& board, BlankHeap& heap, unordered_map<int, vector<int>>& effect_blanks)
	{
		if(heap.empty())
		{
			return true;
		}
		int ij = heap.top();
		int i = ij / 10;
		int j = ij % 10;
		set<char> blank;
		heap.get_blank(ij, blank);
		if(blank.size() == 0)
		{
			return false;
		}
		set<char> e_blank;
		vector<int> real_effect_blanks;
		heap.pop();
		for(char c : blank)
		{
			board[i][j] = c;
			for(int e_ij : effect_blanks[ij])
			{
				if(!heap.get_blank(e_ij, e_blank))
				{
					continue;
				}
				if(e_blank.find(c) != e_blank.end())
				{
					e_blank.erase(c);
					real_effect_blanks.push_back(e_ij);
					heap.modify(e_ij, e_blank);
				}
			}
			if(solveSudokuDFS(board, heap, effect_blanks))
			{
				return true;
			}
			board[i][j] = '.';
			for(int e_ij : real_effect_blanks)
			{
				heap.get_blank(e_ij, e_blank);
				e_blank.insert(c);
				heap.modify(e_ij, e_blank);
			}
			real_effect_blanks.clear();
		}
		heap.push(ij, blank);
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		unordered_map<int, vector<int>> effect_blanks;
		BlankHeap heap;
		unordered_map<int, set<char>> row;
		unordered_map<int, set<char>> col;
		unordered_map<int, set<char>> group;
		int group_index;
		vector<int> blanks;
		for(int i = 0; i < 9; ++i)
		{
			row[i] = set<char>();
			for(int j = 0; j < 9; ++j)
			{
				if(col.find(j) == col.end())
				{
					col[j] = set<char>();
				}
				group_index = (i / 3) * 10 + (j / 3);
				if(group.find(group_index) == group.end())
				{
					group[group_index] = set<char>();
				}
				if(board[i][j] != '.')
				{
					row[i].insert(board[i][j]);
					col[j].insert(board[i][j]);
					group[group_index].insert(board[i][j]);
				}
				else
				{
					blanks.push_back(i * 10 + j);
				}
			}
		}
		int i, j, e_i, e_j, e_group_index;
		for(int blank : blanks)
		{
			set<char> valid_blank;
			i = blank / 10;
			j = blank % 10;
			group_index = (i / 3) * 10 + (j / 3);
			for(char c = '1'; c <= '9'; ++c)
			{
				if(row[i].find(c) != row[i].end())
				{
					continue;
				}
				if(col[j].find(c) != col[j].end())
				{
					continue;
				}
				if(group[group_index].find(c) != group[group_index].end())
				{
					continue;
				}
				valid_blank.insert(c);
			}
			heap.push(blank, valid_blank);
			effect_blanks[blank] = vector<int>();
			for(int e_blank : blanks)
			{
				if(blank != e_blank)
				{
					e_i = e_blank / 10;
					e_j = e_blank % 10;
					e_group_index = (e_i / 3) * 10 + (e_j / 3);
					if(e_i == i || e_j == j || e_group_index == group_index)
					{
						effect_blanks[blank].push_back(e_blank);
					}
				}
			}
		}
		solveSudokuDFS(board, heap, effect_blanks);
		for(int i = 0; i < 9; ++i)
		{
			for(int j = 0; j < 9; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	vector<vector<char>> board;
	board.push_back({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
	board.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
	board.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
	board.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
	board.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
	board.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
	board.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
	board.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
	board.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});
	Solution().solveSudoku(board);
	return 0;
}
