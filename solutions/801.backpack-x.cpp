class Solution {
public:
    // Complete backpack, O(VN), O(V)
    int backPackX(int n) {
        int s = n / 50 + 1;
        bool dp[n / 50 + 1] = {false}; 
        dp[0] = true;
        int m[3] = {3, 5, 7};
        for(int i = 0; i < 3; ++i) {
            for(int j = m[i]; j < s; ++j)
                if(dp[j - m[i]])
                    dp[j] = true;
        }
        while(s) {
            s -= 1;
            if(dp[s])
                return n - s * 50;
        }
    }
};