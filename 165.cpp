// https://leetcode.cn/problems/compare-version-numbers/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int size1 = version1.size();
		int size2 = version2.size();
		int index1 = 0;
		int index2 = 0;
		while(index1 < size1 || index2 < size2)
		{
			int num1 = 0;
			int num2 = 0;
			while(index1 < size1 && version1[index1] != '.')
			{
				num1 = num1 * 10 + version1[index1] - '0';
				++index1;
			}
			while(index2 < size2 && version2[index2] != '.')
			{
				num2 = num2 * 10 + version2[index2] - '0';
				++index2;
			}
			if(num1 > num2)
			{
				return 1;
			}
			else if(num1 < num2)
			{
				return -1;
			}
			else
			{
				++index1;
				++index2;
			}
		}
		return 0;
	}
};

int main()
{
	string version1 = "1.01"; 
	string version2 = "1.001";
	cout << Solution().compareVersion(version1, version2);
	return 0;
}
