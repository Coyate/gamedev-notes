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
	int nthUglyNumber(int n) {
        if(n <= 0)
            return -1;
		vector<int> v(n);
		v[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0, x = 1;
		while (x < n) {
			v[x] = min(min(v[p2] * 2, v[p3] * 3), v[p5] * 5);
			while (v[p2] * 2 <= v[x])
				++p2;
			while (v[p3] * 3 <= v[x])
				++p3;
			while (v[p5] * 5 <= v[x])
				++p5;
			++x;
		}
		return v[x - 1];
	}
};


int main() {
	vector<int> vi{ 1, 2,3,4,5,6,7,8,9,10,1500 };
	Solution s;
	for (auto i : vi)
		std::cout << s.nthUglyNumber(i) << endl;
	return 0;
}