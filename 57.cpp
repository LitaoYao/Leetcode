// https://leetcode.cn/problems/insert-interval/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void insert_back(vector<vector<int>>& intervals, int& size, vector<int>& newInterval)
	{
		if(size == 0)
		{
			intervals.push_back(newInterval);
			++size;
		}
		else
		{
			if(intervals[size - 1][1] >= newInterval[0])
			{
				intervals[size - 1][1] = max(intervals[size - 1][1], newInterval[1]);
			}
			else
			{
				intervals.push_back(newInterval);
				++size;
			}
		}
	}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> newIntervals;
		int new_size = 0;
		int size = intervals.size();
		bool need_insert_new;
		bool has_insert_new = false;
		for(int i = 0; i < size; ++i)
		{
			if(!has_insert_new)
			{
				need_insert_new = false;
				if(newInterval[0] == intervals[i][0])
				{
					if(newInterval[1] < intervals[i][1])
					{
						need_insert_new = true;
					}
				}
				else
				{
					need_insert_new = newInterval[0] < intervals[i][0];
				}
				if(need_insert_new)
				{
					insert_back(newIntervals, new_size, newInterval);
					has_insert_new = true;
				}
			}
			insert_back(newIntervals, new_size, intervals[i]);
		}
		if(!has_insert_new)
		{
			insert_back(newIntervals, new_size, newInterval);
		}
		for(int i = 0; i < new_size; ++i)
		{
			cout << newIntervals[i][0] << " " << newIntervals[i][1] << endl;
		}
		return newIntervals;
    }
};

int main()
{
	vector<vector<int>> intervals;
	intervals.push_back({1, 2});
	intervals.push_back({3, 5});
	intervals.push_back({6, 7});
	intervals.push_back({8, 10});
	intervals.push_back({12, 16});
	vector<int> newInterval = {4, 8};
	Solution().insert(intervals, newInterval);
	return 0;
}
