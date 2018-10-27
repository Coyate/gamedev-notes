class Solution {
public:
    // 01 backpack, O(VN), O(V)
    int backPackV(vector<int> &nums, int target) {
        if(accumulate(nums.begin(), nums.end(), 0) < target)
            return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto i : nums)
            for(int j = target; j >= i; --j)
                dp[j] += dp[j - i];
        return dp[target];
    }
};