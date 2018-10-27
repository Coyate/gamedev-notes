#include <vector> 
#include <algorithm>
using namespace std;


class Solution {
public:
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        vector<double> dp(n + 1, 1.0);
        int s = prices.size();
        for_each(probability.begin(), probability.end(), [](auto &a){a = 1.0 - a;});
        for(int i = 0; i < s; ++i) {
            for(int j = n; j >= prices[i]; --j) {
                dp[j] = min(dp[j], dp[j - prices[i]] * probability[i]);
            }
        }
        return 1.0 - dp[n];
    }
};