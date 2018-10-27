#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <utility>
#include <set>
#include <cmath>
#include "linklist.h"

using namespace std;

class Solution {
public:
	string minNumber(vector<int> &nums) {
		sort(nums.begin(), nums.end(), [](int a, int b) {
			string p(to_string(a) + to_string(b)), q(to_string(b) + to_string(a));
			return p < q;
		});
		string r;
		auto b = find_if(nums.begin(), nums.end(), [](int a) {
			return a != 0;
		});
		while (b != nums.end())
			r.append(to_string(*b++));
		if (r.empty() && !nums.empty())
			return "0";
		return r;
	}
};


int main() {
	vector<vector<int>> vvi{
		{3, 321, 32},
	{ 5, 13 },
	{0},
	{},
	{1, 0},
	{0 ,1,1},
	{1 ,0, 0},
	{0, 0, 0, 0},
	{ 41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55 }
	};

	Solution s;
	for (auto &vi : vvi)
		std::cout << s.minNumber(vi) << endl;
	return 0;
}