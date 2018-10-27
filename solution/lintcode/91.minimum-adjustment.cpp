class Solution {
public:
    // dp, O(N * max(A)), O(max(A))
    int MinAdjustmentCost(vector<int> &A, int target) {
        //int s = *max_element(A.begin(), A.end());
        const int s = 100;
        int dp[s], dp2[s];
        auto *p = dp, *q = dp2;

        for (int j = 0; j < s; ++j)
            p[j] = abs(A[0] - j - 1);

        for (int i = 1; i < A.size(); ++i) {

            int deq[s], head = 0, tail = -1;
            for (int j = 0; j <= target; ++j) {
                while (tail >= head && p[deq[tail]] > p[j])
                    --tail;
                deq[++tail] = j;
            }

            for (int j = 0; j < s; ++j) {
                if (j + target < s) {
                    while (tail >= head && p[deq[tail]] > p[j + target])
                        --tail;
                    deq[++tail] = j + target;
                }
                if (deq[head] < j - target)
                    ++head;
                q[j] = abs(A[i] - j - 1) + p[deq[head]];
            }
            swap(p, q);
        }
        return *min_element(p, p + s);
    }

    // dp, O(N * max(A) * target), O(max(A))
    int MinAdjustmentCost(vector<int> &A, int target) {
        int s = *max_element(A.begin(), A.end());
        int dp[s], dp2[s];
        auto *p = dp, *q = dp2;

        for (int j = 0; j < s; ++j)
            p[j] = abs(A[0] - j - 1);

        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < s; ++j) {
                q[j] = abs(A[i] - j - 1) + *min_element(p + max(0, j - target), p + min(s - 1, j + target + 1));
            }
            swap(p, q);
        }
        return *min_element(p, p + s);
    }

    // dp, O(N * max(A) * target), O(N * max(A))
    int MinAdjustmentCost(vector<int> &A, int target) {
    	int s = *max_element(A.begin(), A.end());
    	vector<vector<int>> dp(A.size(), vector<int>(s));
    	for (int j = 0; j < s; ++j)
    		dp[0][j] = abs(A[0] - j - 1);
    	for (int i = 1; i < A.size(); ++i)
    		for (int j = 0; j < s; ++j) {
    			int last = INT_MAX;
    			for (int k = j - target; k <= j + target; ++k)
    				if (k >= 0 && k < s)
    					last = min(last, dp[i - 1][k]);
    			dp[i][j] = abs(A[i] - j - 1) + last;
    		}
    	int m = INT_MAX;
    	for (int j = 0; j < s; ++j)
    		m = min(m, dp[A.size() - 1][j]);
    	return m;
    }
};