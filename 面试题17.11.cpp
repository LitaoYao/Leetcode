// https://leetcode.cn/problems/find-closest-lcci/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		map<string, vector<int>> wordIndexs;
		int n = words.size();
		for (int i = 0; i < n; ++i)
		{
			wordIndexs[words[i]].push_back(i);
		}
		int ans = INT_MAX;
		int index1 = 0;
		int index2 = 0;
		int n1 = wordIndexs[word1].size();
		int n2 = wordIndexs[word2].size();
		while (index1 < n1 && index2 < n2)
		{
			ans = min(ans, abs(wordIndexs[word1][index1] - wordIndexs[word2][index2]));
			if (wordIndexs[word1][index1] < wordIndexs[word2][index2] && index1 < n1 - 1)
			{
				++index1;
			}
			else
			{
				++index2;
			}
		}
		return ans;
	}
};

int main()
{
	vector<string> words = {"I", "am", "a", "student", "from", "a", "university", "in", "a", "city"};
	string word1 = "a";
	string word2 = "student";
	int ans = Solution().findClosest(words, word1, word2);
	cout << ans << endl;
	return 0;
}
