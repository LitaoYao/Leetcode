// https://leetcode-cn.com/problems/group-anagrams/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string hashString(string str)
	{
		sort(str.begin(), str.end());
		return str;
	}

	string hashString1(string str)
	{
		vector<int> char_counts(26); 
		int size = str.size();
		for(int i = 0; i < size; ++i)
		{
			char_counts[str[i] - 'a'] += 1;
		}
		string hash_str = "";
		for(int i = 0; i < 26; ++i)
		{
			if(char_counts[i] > 0)
			{
				hash_str += 'a' + i;
				hash_str += to_string(char_counts[i]);
			}
		}
		return hash_str;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> str_maps;
		int size = strs.size();
		for(int i = 0; i < size; ++i)
		{
			string hash_str = hashString(strs[i]);
			if(str_maps.find(hash_str) == str_maps.end())
			{
				str_maps[hash_str] = vector<string>();
			}
			str_maps[hash_str].push_back(strs[i]);
		}
		vector<vector<string>> ans(str_maps.size());
		int index = 0;
		for(unordered_map<string, vector<string>>::iterator it = str_maps.begin(); it != str_maps.end(); ++it)
		{
			ans[index++] = it->second;
			cout << it->first << endl;
		}
		return ans;
	}
};

int main()
{
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution().groupAnagrams(strs);
	return 0;
}
