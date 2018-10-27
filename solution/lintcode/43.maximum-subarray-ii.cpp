#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "tree.h"

using namespace std;

class Solution {
public:
	int maxTwoSubArrays(vector<int> &nums) {
		vector<int> l = maxArray(nums);
		reverse(nums.begin(), nums.end());
		vector<int> r = maxArray(nums);
		reverse(r.begin(), r.end());
		int m = INT_MIN;
		for (int i = 0; i < l.size(); ++i)
			m = max(m, l[i] + r[i]);
		return m;
	}
	vector<int> maxArray(vector<int> &nums) {
		vector<int> r(nums.size() - 1);
		int s = nums[0];
		r[0] = nums[0];
		for (int i = 1; i < r.size(); ++i) {
			if (s < 0) s = 0;
			s += nums[i];
			r[i] = max(s, r[i - 1]);
		}
		return r;
	}
};

int main(int argc, char *argr[])
{
	/*vector<int> vi{ 1, 3, -1, 2, -1, 2 };*/
	vector<int> vi{ -1,-2,-3,-100,-1,-50 };
	Solution solu;
	cout << solu.maxTwoSubArrays(vi);
	return 0;
}
