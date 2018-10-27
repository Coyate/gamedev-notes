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
	int digitCounts(int k, int n) {
		int c = 0, d = 0, m = 0;
		if (k == 0)
			c = 1;
		for (int i = 1; i <= n; ++i) {
			d = i;
			while (d) {
				m = d % 10;
				if (m == k)
					++c;
				d /= 10;
			}
		}
		return c;
	}
};


int main() {
	vector<int> vi{ 10, 1, 2,3,4,5,6,7,8,9,1500 };
	Solution s;
	for (auto i : vi)
		std::cout << s.digitCounts(1, i) << endl;
	return 0;
}