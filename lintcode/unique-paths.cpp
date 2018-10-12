//// DP
//// Space O(n), Time O(m)(n) 
//
//class Solution {
//public:
//	/**
//	* @param n, m: positive integer (1 <= n ,m <= 100)
//	* @return an integer
//	*/
//	int uniquePaths(int m, int n) {
//		// wirte your code here
//		int f[101];
//		for (int i = 0; i <= n; i++)
//			f[i] = 0;
//		f[0] = 1;
//		for (int i = 0; i < n; i++) {
//			for (int j = 1; j < m; j++) {
//				f[j] = f[j - 1] + f[j];
//			}
//		}
//		return f[m - 1];
//	}
//};
//
//// DP
//// Space O(mn), Time O(mn) 
//class Solution {
//public:
//	/**
//	* @param n, m: positive integer (1 <= n ,m <= 100)
//	* @return an integer
//	*/
//	int uniquePaths(int m, int n) {
//		// wirte your code here
//		int f[101][101];
//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j <= n; j++)
//				f[i][j] = 0;
//		}
//		f[1][1] = 1;
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				if ((i != 1) || (j != 1)) {
//					f[i][j] = f[i - 1][j] + f[i][j - 1];
//				}			
//			}
//		}
//		return f[m][n];
//	}
//};
//
//// Combination
//// Space: O(1), Time: O(n)
//class Solution {
//public:
//	/**
//	* @param n, m: positive integer (1 <= n ,m <= 100)
//	* @return an integer
//	*/
//	int uniquePaths(int m, int n) {
//		// wirte your code here
//		return combination(m + n - 2, min(m - 1, n - 1));
//	}
//	int combination(int n, int k) {
//		long long sum = 1;
//		for (int i = 1; i <= k; i++, n--) {
//            // sum *= will make precision lost
//			sum = sum * n / i;
//		}
//		return sum;
//	}
//};
//
//// Recur
//class Solution {
//public:
//    /**
//     * @param n, m: positive integer (1 <= n ,m <= 100)
//     * @return an integer
//     */
//	int uniquePaths(int m, int n) {
//		// wirte your code here
//		double num = recur(1, 1, m, n);
//		return num;
//	}
//
//	int recur(int x, int y, int m, int n) {
//		if (x == n && y == m) {
//			return 1;
//		}
//		else if (y == m && x <= n) {
//			return recur(x + 1, y, m, n);
//		}
//		else if (x == n && y <= m) {
//			return recur(x, y + 1, m, n);
//		}
//		else if (x < n && y < m) {
//			return recur(x + 1, y, m, n) + recur(x, y + 1, m, n);
//		}	
//	}
//};
//
//// Stack
//class Solution {
//public:
//	/**
//	* @param n, m: positive integer (1 <= n ,m <= 100)
//	* @return an integer
//	*/
//	int uniquePaths(int m, int n) {
//		// wirte your code here
//		stack <vector <int>> s1;		
//		vector <int> p;
//		s1.push({ 1, 1 });
//		long long num = 0;
//		while (!s1.empty()) {
//			p = s1.top();
//			s1.pop();
//			if (p[0] == m && p[1] < n) {
//				s1.push({ p[0], p[1] + 1});
//			}
//			else if (p[1] == n && p[0] < m) {
//				s1.push({ p[0] + 1, p[1]});
//			}
//			else if (p[0] < m && p[1] < n) {
//				s1.push({ p[0], p[1] + 1 });
//				s1.push({ p[0] + 1, p[1] });
//			}
//			else if (p[0] == m && p[1] == n) {
//				num++;
//			}
//		}
//		return num;
//	}
//};