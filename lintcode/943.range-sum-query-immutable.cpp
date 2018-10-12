class NumArray {
public:
    NumArray(vector<int> nums) {
        dp = new int[nums.size()];
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            dp[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0? dp[j] : dp[j] - dp[i - 1];
    }
    
    int* dp;
};