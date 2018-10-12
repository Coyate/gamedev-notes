#include <vector> 
#include <algorithm>
using namespace std;

// 多重背包化成01背包，采用二进制数量
class Solution {
public:
    int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < prices.size(); ++i) {
		    int k = 1;
		    while(amounts[i] - 2 * k + 1 > 0) {
		        for (int j = n; j >= k * prices[i]; --j)
			        dp[j] = max(dp[j - k * prices[i]] + k * weight[i], dp[j]); 
		        k <<= 1;
		    }
		    k = amounts[i] - k + 1;
		    for (int j = n; j >= k * prices[i]; --j)
			        dp[j] = max(dp[j - k * prices[i]] + k * weight[i], dp[j]); 
		    
		}
		return dp[n];
    }
};


// 多重背包 化成 01背包求解
class Solution {
public:
    int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < prices.size(); ++i)
			for (int k = 1; k <= amounts[i]; ++k)
			    for (int j = n; j >= prices[i]; --j)
			        dp[j] = max(dp[j - prices[i]] + weight[i], dp[j]);
		return dp[n];
    }
};