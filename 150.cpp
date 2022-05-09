// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int stringToNum(string str)
	{
		int num = 0;
		int sign = 1;
		for(char s : str)
		{
			if(s == '-')
			{
				sign = -1;
				continue;
			}
			num = num * 10 + s - '0';
		}
		return num * sign;
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		for(string token : tokens)
		{
			cout << "------------------------" <<endl;
			cout << token << endl;
			if(token == "+")
			{
				int num1 = nums.top();
				nums.pop();
				int num2 = nums.top();
				nums.pop();
				nums.push(num2 + num1);
			}
			else if(token == "-")
			{
				int num1 = nums.top();
				nums.pop();
				int num2 = nums.top();
				nums.pop();
				nums.push(num2 - num1);
			}
			else if(token == "*")
			{
				int num1 = nums.top();
				nums.pop();
				int num2 = nums.top();
				nums.pop();
				nums.push(num2 * num1);
			}
			else if(token == "/")
			{
				int num1 = nums.top();
				nums.pop();
				int num2 = nums.top();
				nums.pop();
				nums.push(num2 / num1);
			}
			else
			{
				nums.push(stringToNum(token));
			}
			cout << nums.top() << endl;
		}
		return nums.top();
	}
};

int main()
{
	vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << Solution().evalRPN(tokens);
	return 0;
}
