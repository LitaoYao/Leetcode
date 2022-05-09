// https://leetcode.cn/problems/restore-ip-addresses/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValid(string ip)
	{
		if(ip == "0")
		{
			return true;
		}
		else if(ip[0] == '0')
		{
			return false;
		}
		if(ip.size() > 3)
		{
			return false;
		}
		int num = 0;
		for(char s : ip)
		{
			num = num * 10 + s - '0';
		}
		return num <= 255;
	}
	void dfs(vector<string>& ans, const string s, int index, vector<string>& group)
	{
		int size = s.size();
		int g_size = group.size();
		string left_ip = s.substr(index, size - index);
		int left_size = left_ip.size();
		if(left_size > (4 - g_size) * 3)
		{
			return;
		}
		string use_ip = "";
		if(g_size == 3 && isValid(left_ip))
		{
			string ip = "";
			for(int i = 0; i < 3; ++i)
			{
				ip += group[i] + ".";
			}
			ip += left_ip;
			cout << ip << endl;
			ans.push_back(ip);
			return;
		}
		for(int i = 1; i <= 3 && index + i < size; ++i)
		{
			use_ip = s.substr(index, i);
			if(isValid(use_ip))
			{
				group.push_back(use_ip);
				dfs(ans, s, index + i, group);
				group.pop_back();
			}
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		vector<string> group;
		dfs(ans, s, 0, group);
		return ans;
	}
};

int main()
{
	Solution().restoreIpAddresses("1111");
	return 0;
}
