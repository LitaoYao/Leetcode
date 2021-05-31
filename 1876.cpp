// https://leetcode-cn.com/problems/substrings-of-size-three-with-distinct-characters/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int countGoodSubstrings(string s) {
		if(s.size() < 3)
		{
			return 0;
		}
		int ans = 0;
		for(int i = 0; i < s.size() - 2; ++i)
		{
			string subs = s.substr(i, 3);
			if(subs[0] != subs[1] && subs[0] != subs[2] && subs[1] != subs[2])
			{
				ans += 1;
			}
		}
		return ans;
	}
};

int main()
{
	string s = "xyzzaz";
	cout << Solution().countGoodSubstrings(s);
	return 0;
}
