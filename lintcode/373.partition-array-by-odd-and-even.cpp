// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	// isOdd
    inline bool isIt(int &i) {
		if (i % 2 == 0)
			return false;
		else
			return true;
	}

	// 运行时间：323ms
	void reOrdernums(vector<int> &nums) {
		if (nums.empty() || nums.size() <= 1)
			return;
		int left = -1;
		int bubbles = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (isIt(nums[i])) {
				++left;
				if (left != i) {
					int temp = nums[i];
					for (int j = i; j > left; --j)
						nums[j] = nums[j - 1];
					nums[left] = temp;
				}
			}
			else {
				++bubbles;
			}
		}
	}

    // 323 ms
    void reOrdernums(vector<int> &nums) {
		stable_partition(nums.begin(), nums.end(), [](int i) {return i % 2 != 0; });
	}
    
    // o(n) buffer, 1ms
};


int main(int argc, char *argv[]) {
	vector<vector<int>> vvi{
	{},
	{0},
	{1},
	{1,2,3,4,5,6,7,8,9}
	};
	Solution solu;
	for (auto &vi : vvi) {
		solu.reOrdernums(vi);
		for (auto const i : vi)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}