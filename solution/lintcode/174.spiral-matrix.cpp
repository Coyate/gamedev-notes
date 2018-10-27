#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
#include <Windows.h>
using namespace std;

#include "tree.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix[0].empty())
			return {};
		vector<int> result;
		int left = 0;
		int right = matrix[0].size() - 1;
		int top = 0;
		int bottom = matrix.size() - 1;
		while (left <= right && top <= bottom) {
			if (left <= right && top <= bottom) {
				for (int i = left; i <= right; ++i) {
					result.push_back(matrix[top][i]);
				}
				++top;
			}
			if (left <= right && top <= bottom) {
				for (int i = top; i <= bottom; ++i) {
					result.push_back(matrix[i][right]);
				}
				--right;
			}
			if (left <= right && top <= bottom) {
				for (int i = right; i >= left; --i) {
					result.push_back(matrix[bottom][i]);
				}
				--bottom;
			}
			if (left <= right && top <= bottom) {
				for (int i = bottom; i >= top; --i) {
					result.push_back(matrix[i][left]);
				}
				++left;
			}
		}
		return result;
	}
};

int main() {

	vector<vector<vector<int>>> vvvi{
		{},
		{{}},
	{
		{1},
		{2}
	},

	{
		{1, 2}
	},

	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	}

	};

	Solution solu;
	for (auto &vvi : vvvi) {
		auto v = solu.spiralOrder(vvi);
		cout << "[";
		for (auto i : v) {
			cout << i << " ";
		}
		cout << "]" << endl;
	}
	system("PAUSE");
	return 0;
}
