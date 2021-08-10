// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string ans = "";
		long long ll_numerator = numerator;
		long long ll_denominator = denominator;
		if((ll_numerator * ll_denominator) < 0)
		{
			ans += "-";
		}
		ll_numerator = abs(numerator);
		ll_denominator = abs(denominator);
		long long before_dot = ll_numerator / ll_denominator;
		ll_numerator %= ll_denominator;
		ll_numerator *= 10;
		string before_dot_ans = "";
		if(before_dot == 0)
		{
			before_dot_ans = "0";
		}
		else
		{
			while(before_dot > 0)
			{
				before_dot_ans = string(1, (before_dot % 10) + '0') + before_dot_ans;
				before_dot /= 10;
			}
		}
		ans += before_dot_ans;
		string dot_ans = "";
		unordered_map<long long, int> num_map;
		int loop_index = -1;
		while(ll_numerator > 0 && dot_ans.size() <= 2 * 1e4)
		{
			if(num_map.find(ll_numerator) != num_map.end())
			{
				loop_index = num_map[ll_numerator];
				break;
			}
			num_map[ll_numerator] = dot_ans.size();
			if(ll_numerator < ll_denominator)
			{
				dot_ans += "0";
				ll_numerator *= 10;
			}
			else
			{
				dot_ans += ((ll_numerator / ll_denominator) + '0');
				ll_numerator %= ll_denominator;
				ll_numerator *= 10;
			}
		}
		int dot_ans_size = dot_ans.size();
		if(loop_index == -1)
		{
			if(dot_ans.size() > 0)
			{
				ans = ans + "." + dot_ans;
			}
		}
		else
		{
			ans = ans + ".";
			for(int i = 0; i < loop_index; ++i)
			{
				ans += dot_ans[i];
			}
			ans += "(";
			for(int i = loop_index; i < dot_ans_size; ++i)
			{
				ans += dot_ans[i];
			}
			ans += ")";
		}
		return ans;
	}
};

int main()
{
	cout << Solution().fractionToDecimal(-1, 2);
	return 0;
}
