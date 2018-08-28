#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 完全背包
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
		vector<int> f(m + 1, 0);
		for (int i = 0; i < A.size(); ++i)
			for (int j = m; j >= 0; --j)
				for (int k = 0; k * A[i] <= m; ++k)
					if (j - k * A[i] >= 0)
						f[j] = max(f[j], f[j - k * A[i]] + k * V[i]);
		return f[m];
    }

    // 转化成01背包
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        vector<int> f(m + 1, 0);
        for(int i = 0; i < A.size(); ++i)
            for(int j = 0; j < m / A[i]; ++j)
                for(int k = m; k >= A[i]; --k)
                    f[k] = max(f[k], f[k - A[i]] + V[i]);
        return f[m];
    }

    // 转化成二进制01背包
    // 无论第i个物品选择几件，最终总是可以表示成二进制个
	int backPackIII(vector<int> &A, vector<int> &V, int m) {
		vector<int> f(m + 1, 0);
		for (int i = 0; i < A.size(); ++i) {
		    int j = 1;
		    while(j * A[i] < m) {
		        for (int k = m; k >= j * A[i]; --k)
					f[k] = max(f[k], f[k - j * A[i]] + j * V[i]j;
		        j = j << 1;
		    }
		}
		return f[m];
	}

    // 连续放入 O(VN)
	int backPackIII(vector<int> &A, vector<int> &V, int m) {
		vector<int> f(m + 1, 0);
		for (int i = 0; i < A.size(); ++i)
			for (int j = A[i]; j <= m; ++j)
				f[j] = max(f[j], f[j - A[i]] + V[i]);
		return f[m];
	}


    // 连续放入 O(VN)，颠倒版
	int backPackIII(vector<int> &A, vector<int> &V, int m) {
		vector<int> f(m + 1, 0);
		for (int j = 0; j <= m; ++j)
			for (int i = 0; i < A.size(); ++i)
				if (j >= A[i])
					f[j] = max(f[j], f[j - A[i]] + V[i]);
		return f[m];
	}
    // 对输入进行优化
    // 1. 删除大于v的
    // 2. 同样weight的，只保留value最大的
};