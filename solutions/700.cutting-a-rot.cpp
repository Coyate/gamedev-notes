class Solution {
public:
    // Compelete backpack, O(VN), O(V)
    int cutting(vector<int> &prices, int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j)
                dp[j] = max(dp[j - i] + prices[i - 1], dp[j]);
        return dp[n];
    }
};