#include <vector> 
#include <algorithm>
using namespace std;

// 多重背包
// 内层循环没有用辅助数组
// 自己想出来的新方法！
class Solution {
public:
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
    	// c++14开始，可以用size_t 声明数组
		// vs2017 不支持
		bool dp[n + 1] = {false};
    	dp[0] = true;
    	int r = 0;
    	for (int i = 0; i < value.size(); ++i) {
    	    int vi = value[i];
    		for (int start = vi; start < 2 * vi; ++start) {
    			int index = start;
    			int mi = amount[i];
    			int seq = mi;
    			while (index <= n) {
    				if (dp[index])
    					seq = mi;
    				else if (dp[index - vi]) {
    					if (!seq)
    						break;
    					dp[index] = true;
    					--seq;
    					++r;
    				}
    				index += vi;
    			}
    		}
    	}
    	return r;
    }
};

// ？？？
// 原地数组法？？
// 50ms
class Solution {
public:
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
    	bool dp[n + 1] = {false};
    	dp[0] = true;
    	int r = 0;
    	for (int i = 0; i < value.size(); ++i) {
    		int c[n + 1] = {0};
    		int v = value[i];
    		int m = amount[i];
    		for (int j = v; j <= n; ++j) {
    			if (!dp[j] && dp[j - v] && c[j - v] < m) {
    				dp[j] = true;
    				++r;
    				c[j] = c[j - v] + 1;
    			}
    		}
    	}
    	return r;
    }
};

// 多重背包找组合数
class Solution {
public:
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
    	vector<bool> dp(n + 1, false);
    	vector<int> c;
    	dp[0] = true;
    	int r = 0;
    	for (int i = 0; i < value.size(); ++i) {
    		c.assign(n + 1, 0);
    		for (int j = value[i]; j <= n; ++j) {
    			if (!dp[j] && dp[j - value[i]] && c[j - value[i]] < amount[i]) {
    				dp[j] = true;
    				++r;
    				c[j] = c[j - value[i]] + 1;
    			}
    		}
    	}
    	return r;
    }
};

// 二进制多重背包
// 使用vector<int> 可以算出每处组合的种数
class Solution {
public:
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
    	vector<bool> dp(n + 1, false);
    	dp[0] = true;
    	for (int i = 0; i < value.size(); ++i) {
    		int k = 1;
    		int s = min(amount[i], n / value[i]);
    		while (s - 2 * k + 1 > 0) {
    			for (int j = n; j >= k * value[i]; --j)
    				if (!dp[j] && dp[j - k * value[i]])
    					dp[j] = true;
    			k <<= 1;
    		}
    		k = s - k + 1;
    		for (int j = n; j >= k * value[i]; --j)
    			if (!dp[j] && dp[j - k * value[i]])
    				dp[j] = true;
    	}
    	return count(dp.begin(), dp.end(), true) - 1;
    }
};
