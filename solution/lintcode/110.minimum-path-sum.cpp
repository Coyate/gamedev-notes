// Time: O(mn), Space : O(1), inplace
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int x = grid[0].size(), y = grid.size();
        for(int i = 1; i < x; ++i)
            grid[0][i] += grid[0][i - 1];
        for(int i = 1; i < y; ++i)
            grid[i][0] += grid[i - 1][0];
        for(int i = 1; i < y; ++i)
            for(int j = 1; j < x; ++j)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        return grid[y - 1][x - 1];
    }
};

// Time: O(mn), Space : O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid[0].size();
        // int dp[n + 1] = {INT_MAX}; // Just initialize one element...
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 1; j <= n; ++j)
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j - 1];
        return dp[n];
    }
};
