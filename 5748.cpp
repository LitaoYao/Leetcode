// https://leetcode-cn.com/problems/minimum-interval-to-include-each-query/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[1] - a[0] < b[1] - b[0];
	}

	void push(vector<vector<int>>& heap, int& tail, const vector<int>& interval)
	{
		heap[tail] = interval;
		shift_up(heap, tail);
		tail += 1;
	}

	void pop(vector<vector<int>>& heap, int& tail)
	{
		heap[0] = heap[tail - 1];
		tail -= 1;
		shift_down(heap, 0, tail);
	}

	void shift_up(vector<vector<int>>& heap, int tail)
	{
		vector<int> tmp = heap[tail];
		while(tail > 0 && cmp(tmp, heap[(tail - 1) >> 1]))
		{
			heap[tail] = heap[(tail - 1) >> 1];
			tail = (tail - 1) >> 1;
		}
		heap[tail] = tmp;
	}

	void shift_down(vector<vector<int>>& heap, int cnt, int tail)
	{
		vector<int> tmp = heap[cnt];
		while(2 * cnt + 1 < tail)
		{
			int left = 2 * cnt + 1;
			int right = left + 1;
			int child = left;
			if(right < tail && cmp(heap[right], heap[left]))
			{
				child = right;
			}
			if(cmp(tmp, heap[child]))
			{
				break;
			}
			heap[cnt] = heap[child];
			cnt = child;
		}
		heap[cnt] = tmp;
	}

	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		int i_size = intervals.size();
		int q_size = queries.size();
		unordered_map<int, int> res;
		vector<int> sort_queries = queries;
		vector<vector<int>> intervals_heap(i_size);
		sort(sort_queries.begin(), sort_queries.end());
		sort(
			intervals.begin(),
			intervals.end(),
			[=](const vector<int>& a, const vector<int>& b)
			{
				if(a[0] == b[0])
				{
					return a[1] < b[1];
				}
				else
				{
					return a[0] < b[0];
				}
			}
		);
		int interval_tail = 0;
		int heap_tail = 0;
		for(int i = 0; i < q_size; ++i)
		{
			while(interval_tail < i_size && intervals[interval_tail][0] <= sort_queries[i])
			{
				push(intervals_heap, heap_tail, intervals[interval_tail]);
				interval_tail += 1;
			}
			while(heap_tail > 0 && intervals_heap[0][1] < sort_queries[i])
			{
				pop(intervals_heap, heap_tail);
			}
			if(heap_tail > 0)
			{
				res[sort_queries[i]] = intervals_heap[0][1] - intervals_heap[0][0] + 1;
			}
			else
			{
				res[sort_queries[i]] = -1;
			}
		}
		vector<int> ans(q_size);
		for(int i = 0; i < q_size; ++i)
		{
			ans[i] = res[queries[i]];
		}
		return ans;
	}
};
