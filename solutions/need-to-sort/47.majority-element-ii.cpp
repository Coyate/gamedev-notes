#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "tree.h"

using namespace std;


class Solution {
public:
    // 排序检查法
    int majorityNumber(vector<int> &nums) {
	    sort(nums.begin(), nums.end());
	    int s = nums.size() / 3;
	    return count(nums.begin(), nums.end(), nums[s - 1]) > s? nums[s - 1] : nums[2 * s + 1];
    }

    // 摩尔投票法
	int majorityNumber(vector<int> &nums, int k) {
		map<int, int> m;
		for (auto i : nums) {
			m[i] += 1;
			if(m.size() == k) {
				for (auto &p : m)
					p.second -= 1;
				auto b = m.begin();
				while (b != m.end()) {
					if (b->second == 0)
						b = m.erase(b);
					else
						++b;
				}
			}
		}
		for (auto &p : m)
			p.second = 0;
		int max = 0, count = 0;
		for (auto i : nums) {
			auto iter = m.find(i);
			if (iter != m.end()) {
				iter->second += 1;
				if (iter->second > count) {
					max = iter->first;
					count = iter->second;
				}	
			}
		}
		return max;
	}
};

int main(int argc, char *argr[])
{
	vector<int> vi{ 3,1,2,3,2,3,3,4,4,4 };
	Solution solu;
	cout << solu.majorityNumber(vi, 3);
	return 0;
}
