// https://leetcode.cn/problems/simplify-path/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void stack_in(vector<string>& dirs, string dir)
	{
		dirs.push_back(dir);
	}
	void stack_out(vector<string>& dirs)
	{
		if(dirs.size())
		{
			dirs.pop_back();
		}
	}
	void deal_dir(vector<string>& dirs, string dir)
	{
		if(dir == "..")
		{
			stack_out(dirs);
		}
		else if(dir != "." && dir != "")
		{
			stack_in(dirs, dir);
		}
	}
	string simplifyPath(string path) {
		vector<string> dirs;
		string dir = "";
		for(int i = 0; path[i] != '\0'; ++i)
		{
			if(path[i] == '/')
			{
				deal_dir(dirs, dir);
				dir = "";
			}
			else
			{
				dir += path[i];
			}
		}
		deal_dir(dirs, dir);
		int dir_size = dirs.size();
		string ans = "";
		for(int i = 0; i < dir_size; ++i)
		{
			ans += "/" + dirs[i];
		}
		if(ans == "")
		{
			ans = "/";
		}
		return ans;
	}
};

int main()
{
	cout << Solution().simplifyPath("/a/./b/../../c/");
	return 0;
}
