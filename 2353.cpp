// https://leetcode.cn/problems/design-a-food-rating-system/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class FoodRatings {
public:
	FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		int n = foods.size();
		for (int i = 0; i < n; ++i)
		{
			allFoods[foods[i]] = cuisines[i];
			foodRatings[foods[i]] = -ratings[i];
			allRatings[cuisines[i]][-ratings[i]].insert(foods[i]);
		}
	}

	void changeRating(string food, int newRating) {
		int nowR = foodRatings[food];
		string nowC = allFoods[food];
		allRatings[nowC][nowR].erase(food);
		if (allRatings[nowC][nowR].size() == 0)
		{
			allRatings[nowC].erase(nowR);
		}
		foodRatings[food] = -newRating;
		allRatings[nowC][-newRating].insert(food);
	}

	string highestRated(string cuisine) {
		return *(allRatings[cuisine].begin()->second.begin());
	}
	map<string, int> foodRatings;
	map<string, string> allFoods;
	map<string, map<int, set<string>>> allRatings;
};

int main()
{
	vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
	vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
	vector<int> ratings = {9, 12, 8, 15, 14, 7};
	FoodRatings foodRatings = FoodRatings(foods, cuisines, ratings);
	cout << foodRatings.highestRated("korean") << endl; // 返回 "kimchi"
	// "kimchi" 是分数最高的韩式料理，评分为 9 。
	cout << foodRatings.highestRated("japanese") << endl; // 返回 "ramen"
	// "ramen" 是分数最高的日式料理，评分为 14 。
	foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
	cout << foodRatings.highestRated("japanese") << endl; // 返回 "sushi"
	// "sushi" 是分数最高的日式料理，评分为 16 。
	foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
	cout << foodRatings.highestRated("japanese") << endl; // 返回 "ramen"
	// "sushi" 和 "ramen" 的评分都是 16 。
	// 但是，"ramen" 的字典序比 "sushi" 更小。
	return 0;
}
