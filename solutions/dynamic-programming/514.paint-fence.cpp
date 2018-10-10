class Solution {
public:
    int numWays(int n, int k) {
        int dp[3] = {k, k * k};
        for(int i = 2; i < n; ++i) {
            dp[2] = (dp[0] + dp[1]) * (k - 1);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return n < 3? dp[n - 1] : dp[2];
    }
};