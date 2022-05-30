// https://leetcode.cn/problems/sender-with-largest-word-count/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string largestWordCount(vector<string>& messages, vector<string>& senders) {
		map<string, int> counts;
		int maxCount = 0;
		int n = messages.size();
		for(int i = 0; i < n; ++i)
		{
			counts[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
			maxCount = max(maxCount, counts[senders[i]]);
		}
		vector<string> ans;
		for (auto sender : counts)
		{
			if (sender.second == maxCount)
			{
				ans.push_back(sender.first);
			}
		}
		sort(ans.begin(), ans.end());
		reverse(ans.begin(), ans.end());
		return ans[0];
	}
};

int main()
{
	vector<string> messages = {"How is leetcode for everyone", "Leetcode is useful for practice"};
	vector<string> senders = {"Bob", "Charlie"};
	string ans = Solution().largestWordCount(messages, senders);
	cout << ans << endl;
	return 0;
}
