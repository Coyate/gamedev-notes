#include <vector>
#include <iostream>
#include <algorithm>
#include <ciso646>
using namespace std;

// 完全背包
// 时间优化

class Solution {
public:
	int backPackVI(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int j = 1; j <= target; ++j) {
			for (int i : nums) {
				if (j < i) {
					break;
				}
				else {
					dp[j] += dp[j - i];
				}
			}
		}
		return dp[target];
	}
};



// 完全背包
// 直接累加次数
class Solution {
public:
	int backPackVI(vector<int> &nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int j = 1; j <= target; ++j)
			for (int i : nums)
				if (j >= i)
					dp[j] += dp[j - i];
		return dp[target];
	}
};



// 完全背包
// backpack
// 跟随和进行方法次数的累加
class Solution {
public:
	int backPackVI(vector<int> &nums, int target) {
		vector<int> dp(target + 1, INT_MIN);
		dp[0] = 0;
		vector<int> g(target + 1, 0);
		g[0] = 1;
		for (int j = 1; j <= target; ++j)
			for (int i : nums)
				if (j >= i) {
					int n = dp[j - i] + i;
					g[j] += (n >= dp[j] ? g[j - i] : 0);
					dp[j] = max(dp[j], n);
				}
		return g[target];
	}
};

// traceback
// overtime
class Solution {
public:
	/**
	* @param nums: an integer array and all positive numbers, no duplicates
	* @param target: An integer
	* @return: An integer
	*/
	void dfs(const vector<int> &v, int t, int &r) {
		if (!t) {
			++r;
			return;
		}
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] > t) break;
			dfs(v, t - v[i], r);
		}
	}
	int backPackVI(vector<int> &nums, int target) {
		if (nums.empty() or !target)
			return 0;
		int r = 0;
		dfs(nums, target, r);
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
	auto a = s.backPackVI(V, n);
	return 0;
}