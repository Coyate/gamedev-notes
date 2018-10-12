#include <iostream>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin2(vector<int> &nums) {
        if (nums.empty()) {
			return 0;
		}

		size_t l = 0;
		size_t r = nums.size() - 1;
		size_t m = l;

		while (nums[l] >= nums[r]) {

			if (r - l == 1) {
				m = r;
				break;
			}

			m = (r + l) >> 1;

			if (nums[l] == nums[r] && nums[l] == nums[m]) {
				for (size_t i = l; i < r; ++i) {
					if (nums[i] > nums[i + 1])
						return nums[i + 1];
				}
				return nums[l];
			}

			if (nums[m] >= nums[l]) {
				l = m;
			}
			else if (nums[m] <= nums[r]) {
				r = m;
			}
		}
		return nums[m];
	}

	int findMin(vector<int> &nums) {
		return nums.empty()? 0:*min_element(nums.begin(), nums.end());
	}
};




int main(int argc, char *argv[]) {
	vector<vector<int>> vvi{
		// 边界测试
		{},
		{1},
		// 功能测试	
		{1,2,3},
		{2,3,4,5,6,7,8,9,10,1},
		{4,5,6,7,8,9,1,2,3},
		{7,8,9,1,2,3,4,5,6},
		{1,1,1,1,0,1,1}
	};
	Solution solu;
	for (auto &vi : vvi) {
		cout << solu.findMin(vi) << endl;
	}

	system("PAUSE");
	return 0;
}
