// https://leetcode.cn/problems/move-pieces-to-obtain-a-string/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool canChange(string start, string target) {
		string startWithoutSpace = "";
		vector<int> startPos;
		int index = 0;
		for (char& c : start)
		{
			if (c != '_')
			{
				startWithoutSpace += c;
				startPos.push_back(index);
			}
			++index;
		}
		startWithoutSpace += '\0';
		string targetWithoutSpace = "";
		vector<int> targetPos;
		index = 0;
		for (char& c : target)
		{
			if (c != '_')
			{
				targetWithoutSpace += c;
				targetPos.push_back(index);
			}
			++index;
		}
		targetWithoutSpace += '\0';
		if (startWithoutSpace != targetWithoutSpace)
		{
			return false;
		}
		for (int i = 0; startWithoutSpace[i] != '\0'; ++i)
		{
			if (startWithoutSpace[i] == 'L')
			{
				if (startPos[i] < targetPos[i])
				{
					return false;
				}
			}
			if (startWithoutSpace[i] == 'R')
			{
				if (startPos[i] > targetPos[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	string start = "_L__R__R_";
	string target = "L______RR";
	bool ans = Solution().canChange(start, target);
	cout << ans << endl;
	return 0;
}

