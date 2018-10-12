//// DP
//// Space: O(n), Time: O(mn)
//class Solution {
//public:
//	/**
//	* @param n, m: positive integer (1 <= n ,m <= 100)
//	* @return an integer
//	*/
//	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
//		// wirte your code here
//		int n = obstacleGrid[0].size();
//		int m = obstacleGrid.size();
//		vector <int> f;
//		for (int i = 0; i < m; i++)
//			f.push_back(0);
//		f[0] = 1;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (obstacleGrid[j][i]) {
//					f[j] = 0;
//				}
//				else if (j != 0){
//					f[j] = f[j - 1] + f[j];
//				}
//			}
//		}
//		return f[m - 1];
//	}
//};