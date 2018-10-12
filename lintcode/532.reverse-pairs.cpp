#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <utility>
#include <set>
using namespace std;

class Solution {
public:
    // merge & count
    long long reversePairs(vector<int> &A) {
		if (A.size() <= 1)
			return 0;
		int s = A.size() / 2;
		long long r = 0;
		vector<int> v1, v2;
		v1.assign(A.begin(), A.begin() + s);
		v2.assign(A.begin() + s, A.end());
		r += reversePairs(v1);
		r += reversePairs(v2);
		int s1 = v1.size() - 1, s2 = v2.size() - 1;
		s = A.size() - 1;
		while (s1 >= 0 && s2 >= 0) {
			if (v1[s1] > v2[s2]) {
				A[s--] = v1[s1--];
				r += s2 + 1;
			}
			else
				A[s--] = v2[s2--];
		}
		while (s1 >= 0)
			A[s--] = v1[s1--];
		while (s2 >= 0) {
			A[s--] = v2[s2--];
		}
		return r;
    }

    // STL o(n^2)
    long long reversePairs(vector<int> &A) {
		if (A.size() <= 1)
			return 0;
		int s = A.size() / 2;
		long long r = 0;
		vector<int> v1(A.begin(), A.begin() + s), v2(A.begin() + s, A.end());
		r += reversePairs(v1) + reversePairs(v2);
		for (auto i : v1)
			r += lower_bound(v2.begin(), v2.end(), i) - v2.begin();
		sort(A.begin(), A.end());
		return r;
    }

    // 针对解法o(n)+o(n^2)
    long long reversePairs(vector<int> &A) {
        if (is_sorted(A.begin(), A.end(), greater_equal<int>())) {
    		long long n = A.size();
			return (n - 1) * n / 2;
		}
		vector<int> v;
		long long c = 0;
		for (auto i : A) {
			auto b = v.begin();
			while (b != v.end()) {
				if (*b > i)
					++c, ++b;
				else {
					b = v.insert(b, i);
					break;
				}
			}
			if (b == v.end())
				v.push_back(i);
		}
		return c;
    }
};




int main() {
	vector<int> vi{ 4,3,2,1 };
	// cout << merge(vi, 0, vi.size() - 1);

	return 0;
}