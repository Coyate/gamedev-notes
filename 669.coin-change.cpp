class Solution {
public:
    // Complete backpack, O(VN), O(V)
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(auto c : coins)
            for(int j = c; j <= amount; ++j)
                if(dp[j - c] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - c] + 1);
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};