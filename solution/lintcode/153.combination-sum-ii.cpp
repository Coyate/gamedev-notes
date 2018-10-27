#include <vector>
#include <iostream>
#include <algorithm>
#include <ciso646>
using namespace std;
// Third Ac
class Solution {
public:
	void dfs(const vector<int> &v, vector<vector<int>> &r, vector<int> &t, int sum, int start) {
		if (!sum) {
			r.push_back(t);
			return;
		}
		for (int i = start; i < v.size(); ++i) {
            // if (v[i] > sum) break;
            // 判重
			if (i != start and v[i] == v[i - 1]) continue;
            // v排过序
			if (v[i] > sum) break;
			t.push_back(v[i]);
            // 每个元素只用一次
			dfs(v, r, t, sum - v[i], i + 1);
			t.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		if (candidates.empty() or !target)
			return {};
		vector<vector<int>> r;
		vector<int> t;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, r, t, target, 0);
		return r;
	}
};

// Second AC
// lambda compare to defend duplicate || used
class Solution {
public:
	void dfs(const vector<int> &v, vector<vector<int>> &r, vector<int> &t, int sum, int start, vector<bool> &used) {
		if (sum == 0) {
			if (find_if(r.begin(), r.end(), [&](auto a) {return t == a; }) == r.end()) {
				r.push_back(t);
				return;
			}
		}
		for (int i = start; i < v.size() and sum >= v[i]; ++i) {
			if (!used[i]) {
				t.push_back(v[i]);
				used[i] = true;
				dfs(v, r, t, sum - v[i], i, used);
				used[i] = false;
				t.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		if (candidates.empty() || !target)
			return {};
		vector<vector<int>> r;
		vector<int> t;
		vector<bool> used(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		dfs(candidates, r, t, target, 0, used);
		return r;
	}
};

// first AC
// clear duplicate || used
class Solution {
public:
	void dfs(const vector<int> &v, vector<vector<int>> &r, vector<int> &t, int sum, int start, vector<bool> &used) {
		if (sum == 0) {
			r.push_back(t);
			return;
		}
		for (int i = start; i < v.size() and sum >= v[i]; ++i) {
			if (!used[i]) {
				t.push_back(v[i]);
				used[i] = true;
				dfs(v, r, t, sum - v[i], i, used);
				used[i] = false;
				t.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		if (candidates.empty() || !target)
			return {};
		vector<vector<int>> r;
		vector<int> t;
		vector<bool> used(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		dfs(candidates, r, t, target, 0, used);
		if (!r.empty()) {
			int m = 0;
			sort(r.begin(), r.end());
			for (int i = 0; i < r.size(); ++i) {
				if (r[m] != r[i]) {
					swap(r[++m], r[i]);
				}
			}
			r.erase(r.begin() + m + 1, r.end());
		}
		return r;
	}
};

int main() {
	int n = 0;
	cin >> n;
	vector<int> V;
	int i = 0;
	while (cin >> i) {
		V.push_back(i);
	}


	Solution s;
	auto a = s.combinationSum2(V, n);
	return 0;
}