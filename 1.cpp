// https://leetcode-cn.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		size_t v_nums_size = nums.size();
		std::map<int, int> v_index;
		std::vector<int> v_indices(2);
		for (int i = 0; i < v_nums_size; ++i) {
			int v_nums_remain = target - nums[i];
			std::map<int, int>::iterator v_index_iter = v_index.find(v_nums_remain);
			if (v_index_iter == v_index.end()) {
				v_index.insert(std::make_pair(nums[i], i));
			}
			else {
				v_indices[0] = v_index_iter->second;
				v_indices[1] = i;
				return v_indices;
			}
		}
	}
};

int main()
{
	int numbers[] = {2, 5, 0, 8, 6, 11, 7};
	int target = 9;
	std::vector<int> v_nums(numbers, numbers + 7);
	std::vector<int> v_indices = Solution().twoSum(v_nums, target);
	size_t v_indices_size = v_indices.size();
	for (int i = 0; i < v_indices_size; ++i) {
		cout << v_indices[i] << endl;
	}
	return 0;
}
