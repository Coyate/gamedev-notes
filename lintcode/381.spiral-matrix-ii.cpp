#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> v(n);
		for (auto &i : v)
			i.resize(n);
		int l = 0, r = n - 1;
		int t = 0, b = n - 1;
		int c = 1;
		while (l <= r && t <= b) {
			if (l <= r && t <= b) {
				for (int i = l; i <= r; ++i)
					v[t][i] = c++;
				++t;
			}
			if (l <= r && t <= b) {
				for (int i = t; i <= b; ++i)
					v[i][r] = c++;
				--r;
			}
			if (l <= r && t <= b) {
				for (int i = r; i >= l; --i)
					v[b][i] = c++;
				--b;
			}
			if (l <= r && t <= b) {
				for (int i = b; i >= t; --i)
					v[i][l] = c++;
				++l;
			}
		}
		return v;
	}
};

// matrix match solution
class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        step[0][0] = 0;
        step[0][1] = 1;
        step[1][0] = 1;
        step[1][1] = 0;
        step[2][0] = 0;
        step[2][1] = -1;
        step[3][0] = -1;
        step[3][1] = 0;
        vector<vector<int> > ret(n, vector<int>(n));
        memset(canUse, true, sizeof(canUse));
        dfs(1, ret, 0, 0, -1);
        
        return ret;
    }

private:
    int step[4][2];
    bool canUse[100][100];
public:
    void dfs(int dep, vector<vector<int> > &matrix, int direct, int x, int y)
    {
        for(int i = 0; i < 4; i++)
        {
            int j = (direct + i) % 4;
            int tx = x + step[j][0];
            int ty = y + step[j][1];
            if (0 <= tx && tx < matrix.size() && 0 <= ty && ty < matrix[0].size() && canUse[tx][ty])
            {
                canUse[tx][ty] = false;
                matrix[tx][ty] = dep;              
                dfs(dep + 1, matrix, j, tx, ty);               
            }            
        }
    }
};