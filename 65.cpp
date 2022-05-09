// https://leetcode.cn/problems/valid-number/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
	bool check_number(string temp, bool has_sign, bool need_number)
	{
		if(temp.size() > 0)
		{
			int j = 0;
			if(has_sign && (temp[0] == '+' || temp[0] == '-')) j++;
			if(need_number && (j >= temp.size())) return false;
    		for(; j < temp.size(); ++j)
    		{
    			if(temp[j] >= '0' && temp[j] <= '9')
    			{
    				continue;
    			}
    			return false;
			}
			return true;
		}
		return true;
	}
	
    bool isNumber(string s) {
    	// ÕýÔò£º[+-]?\d*(\.\d*)?([eE]\d*)?
    	string temp = "";
    	string last_temp = "";
    	int step = 0;
    	int left = 0;
    	while(s[left] == ' ' && left < s.size()) left++;
    	int right = s.size() - 1;
    	while(s[right] == ' ' && right > 0) right--;
        for(int i = left; i <= right; ++i)
        {
        	if(s[i] == ' ')
        	{
        		return false;
        	}
        	else if(s[i] == '.' && step == 0)
        	{
        		if(!check_number(temp, true, false)) return false;
        		if(temp != "") last_temp = temp;
				temp = "";
				step++;
			}
        	else if((s[i] == 'e') && step <= 1)
        	{
        		if(temp == "" && last_temp == "") return false;
        		if(!check_number(temp, step==0, false)) return false;
        		if(temp != "") last_temp = temp;
				temp = "";
				step=2;
			}
			else if(step <= 2)
        	{
				temp += s[i];
			}
			if(step > 2)
			{
				return false;
			}
        }
        if(step == 0 && temp == "") return false;
        if(step == 0 && !check_number(temp, true, true)) return false;
        if(step == 1 && temp == "" && (last_temp == "" || last_temp == "+" || last_temp == "-")) return false;
        if(step == 1 && !check_number(temp, false, false)) return false;
        if(step == 2 && temp == "") return false;
        if(step == 2 && (last_temp == "" || last_temp == "+" || last_temp == "-")) return false;
        if(step == 2 && !check_number(temp, true, true)) return false;
        return true;
    }
};

int main()
{
	Solution s;
	cout << s.isNumber("46.e3") << endl;
}

