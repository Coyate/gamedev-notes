class Solution {
public:
    // Complete backpack, O(VN), O(V)
    int backPackIV(vector<int> &nums, int target) {
        int dp[target + 1] = {0};
        dp[0] = 1;
        for (auto i : nums)
            for (int j = i ; j <= target; ++j)
                if(dp[j - i])
                    dp[j] += dp[j - i];
        return dp[target];
    }
};