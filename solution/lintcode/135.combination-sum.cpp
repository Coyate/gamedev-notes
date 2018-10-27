#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // backtrace
    // 8ms
	void dfs(const vector<int> &v, vector<vector<int>> &r, vector<int> &t, int sum, int start) {
		if (sum == 0) {
		    r.push_back(t);
		    return;
		}
		for (int i = start; i < v.size() and sum >= v[i]; ++i) {
			t.push_back(v[i]);
			dfs(v, r, t, sum - v[i], i);
			t.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> r;
		vector<int> t;
		sort(candidates.begin(), candidates.end());
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
		dfs(candidates, r, t, target, 0);
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
	auto a = s.combinationSum(V, n);
	return 0;
}