class Solution {
public:
    // 01 backpack, O(VN), O(V)
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        vector<int> f(m + 1, 0);
        for(int i = 0; i < A.size(); ++i)
            for(int c = m; c >= A[i]; --c)
                f[c] = max(f[c], f[c - A[i]] + V[i]);
        return f[m];
    }
};