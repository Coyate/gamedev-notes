class Solution {
public:

	// 01 backpack, O(VN), O(V)
	int backPack(int m, vector<int> &A) {
		vector<int> v(m + 1, 0);
		for (auto c : A) {
			for (int j = m; j >= c; --j) {
					v[j] = max(v[j], v[j - c] + c);
			}
		}
		return v[m];
	}

	int backPack(int V, vector<int> &c) {
		bool dp[V + 1] = {false};
		dp[0] = true;
		for (int i = 0; i < c.size(); ++i) {
		    int s = c[i];
			for (int j = V; j >= s; --j)
				if(dp[j - s] && !dp[j])
					dp[j] = dp[j - s];
		}
		for (int i = V; i >= 0; --i)
			if (dp[i])
				return i;
	}
};