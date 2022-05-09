// https://leetcode.cn/problems/gas-station/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int index = -1;
		int sum = 0;
		int total_sum = 0;
		int size = gas.size();
		for(int i = 0; i < size; ++i)
		{
			sum += (gas[i] - cost[i]);
			total_sum += (gas[i] - cost[i]);
			if(sum < 0)
			{
				index = -1;
				sum = 0;
			}
			else if(index == -1)
			{
				index = i;
			}
		}
		if(total_sum < 0)
		{
			return -1;
		}
		else
		{
			return index;
		}
	}
};

int main()
{
	vector<int> gas = {1, 2, 3, 4, 5};
	vector<int> cost = {3, 4, 5, 1, 2};
	cout << Solution().canCompleteCircuit(gas, cost);
	return 0;
}
