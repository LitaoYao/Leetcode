#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		int size = s.size();
		string ans = "";
		for(int i = 0; i < numRows; ++i)
		{
			for(int j = i; j < size;)
			{
				ans += s[j];
				if(i != 0 && i != numRows - 1)
				{
					int mid_j = j + 2 * (numRows - 1 - i);
					if(mid_j < size)
					{
						ans += s[mid_j];
					}
				}
				if(numRows == 1)
				{
					++j;
				}
				else
				{
					j = j + 2 * (numRows - 1);
				}
			}
		}
		return ans;
    }
};

int main()
{
	Solution solution = Solution();
	string s = "PAYPALISHIRING";
	int numRows = 2;
	cout << solution.convert(s, numRows) << endl;
	return 0;
}
