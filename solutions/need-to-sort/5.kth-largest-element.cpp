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
	int kthLargestElement(int n, vector<int> &nums) {
		if (n > nums.size())
			return -1;
		auto nth = nums.end() - n;
		nth_element(nums.begin(), nth, nums.end());
		return *nth;
	}

    int kthLargestElement2(int n, vector<int> &nums) {
		if (n > nums.size())
			return -1;
		int l = 0, r = nums.size() - 1;
		int p = partition(nums, l, r);
		while (l <= r) {
			int k = nums.size() - p;
			if (k == n)
				return nums[p];
			else if (k < n)
				r = p - 1;
			else
				l = p + 1;
			p = partition(nums, l, r);
		}
		return nums[l];
	}

	int partition(vector<int> &v, int l, int r) {
		if (l >= r)
			return l;
		swap(v[l], v[r]);
		int s = l - 1;
		for (int i = l; i <= r; ++i)
			if (v[i] <= v[r] && i != s)
				swap(v[++s], v[i]);
		return s;
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
		std::cout << s.kthLargestElement(2, vi) << endl;
	return 0;
}