// https://leetcode.cn/problems/max-points-on-a-line/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution 
{
	public:
		bool on_same_line(vector<int> &p1, vector<int> &p2, vector<int> &p3)
		{
			if(p1[0] == p2[0] && p1[0] == p3[0]) return true;
			if(p1[1] == p2[1] && p1[1] == p3[1]) return true;
			if((long long)(p1[0] - p2[0]) * (long long)(p1[1] - p3[1]) == (long long)(p1[0] - p3[0]) * (long long)(p1[1] - p2[1])) return true;
			return false;
		}

		bool same_point(vector<int> &p1, vector<int> &p2)
		{
			return (p1[0] == p2[0] && p1[1] == p2[1]);
		}

		int maxPoints(vector<vector<int> >& points) 
		{
			int n = points.size();
			if(n <= 2) return n;
			sort(points.begin(), points.end());
			vector<vector<int> > point_set = vector<vector<int> >();
			point_set.reserve(n);
			vector<int> p = points[0];
			p.push_back(1);
			for(int i = 1; i < n; ++i)
			{
				if(same_point(points[i], p))
				{
					++p[2];
				}
				else
				{
					point_set.push_back(p);
					p = points[i];
					p.push_back(1);
				}
			}
			point_set.push_back(p);
			n = point_set.size();
			int ans = 0;
			if(n <= 2) 
			{
				for(int i = 0; i < n; ++i)
				{
					ans += point_set[i][2];
				}
			}
			else
			{
				for(int i = 0; i < n - 1; ++i)
				{
					for(int j = i + 1; j < n; ++j)
					{
						int cnt = point_set[i][2] + point_set[j][2];
						for(int k = 0; k < n; ++k)
						{
							if(i == k || j == k) continue;
							if(on_same_line(point_set[i], point_set[j], point_set[k])) cnt += point_set[k][2];
						}
						ans = max(ans, cnt);
					}
				}
			}
			return ans;
		}
};

int main()
{
	int points_list[] = {\
		1, 1, \
		1, 1, \
		1, 1, \
	};

	Solution s;
	vector<vector<int> > points;
	vector<int> p;
	int n = sizeof(points_list) / sizeof(points_list[0]);
	for(int i = 0; i < n; i += 2)
	{
		p.push_back(points_list[i]);	
		p.push_back(points_list[i + 1]);
		points.push_back(p);
		p.clear();
	}
	cout << s.maxPoints(points) << endl;
}
