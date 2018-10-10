#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <memory>
using namespace std;

template <typename T>
void print(const T &words) {
	for (auto const &c : words) {
		cout << c << " ";
	}
	cout << endl;
}

class Solution {
public:
	/**
	* @param matrix: matrix, a list of lists of integers
	* @param target: An integer
	* @return: a boolean, indicate whether matrix contains target
	*/
	int searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int count = 0;
		int row = matrix[0].size() - 1, col = 0;
		while (row >= 0 && col < matrix.size()) {
			if (matrix[col][row] == target) {
				++count;
				--row;
			}
			else if (matrix[col][row] > target) {
				--row;
			}
			else if (matrix[col][row] < target) {
				++col;
			}
		}
		return count;
	}
};

int main(int argc, char *argv[]) {

	vector<vector<vector<int>>> tests{
	{ { 1, 1 } },

	{
		{ 1 },
		{ 1 }
	},

	{
		{ 0, 1 },
		{ 1, 4 }
	},

	{
		{ -1, -1, 1 },
		{ -1, 1, 1 },
		{ 2, 3, 4 }

	},


	{
		{ 62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80 },
		{ 63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81 },
		{ 64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82 },
		{ 65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83 },
		{ 66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84 },
		{ 67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85 }
	},

	{},

	{ {} },

	{ {},{} },

	{ { 0 } },

	{ { 1 } },

	{ { -1 } },

	{ { 2, 100, 103 },
	{ 187, 197, 543 },
	{ 88891, 12358012,  1248212134 } }
	};
	Solution solu;

	for (auto &test : tests) {
		cout << solu.searchMatrix(test, 1) << endl;
	}
	system("PAUSE");
	return 0;
}
