class Solution {
public:
    // 01 backpack, O(VN), O(V)
    bool cardGame(vector<int> &cost, vector<int> &damage, int totalMoney, int totalDamage) {
        vector<int> dp(totalMoney + 1, 0);
        for(int i = 0; i < cost.size(); ++i)
            for(int j = totalMoney; j >= cost[i]; --j)
                dp[j] = max(dp[j], dp[j - cost[i]] + damage[i]);
        return dp[totalMoney] >= totalDamage;
    }
};