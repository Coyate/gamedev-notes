#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int majorityNumber1(vector<int> &nums) {
		if (nums.empty())
			return int();
		int r = nums[0];
		int c = 0;
		for (auto n : nums) {
			if (r == n)
				++c;
			else {
				--c;
				if (c == 0)
					r = n, c = 1;
			}
		}
		return r;
	}

    int majorityNumber2(vector<int> &nums) {
        int r = nums[0], c = 0;
        for (auto n : nums) {
            c += r == n ? 1 : -1;
            if (c == 0)
                r = n, c = 1;
    }
		return r;
	}

    int majorityNumber3(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};