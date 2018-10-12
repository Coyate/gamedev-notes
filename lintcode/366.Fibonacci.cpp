class Solution{
public:
    int fibonacci(int n) {
        int a = 0, b = 1;
        for(int i = 1; i < n; ++i) {
            a += b;
            swap(a, b);
        }
        return a;
    }

    int fibonacci(int n) {
        int dp[n + 1] = { 0 };
        dp[1] = 1;
        for(int i = 2;  i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n - 1];
    }
};