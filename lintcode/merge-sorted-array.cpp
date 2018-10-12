// Space: O(1) Time: O(m+n)
//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdio>
//#include <cctype>
//using namespace std;
//
//class Solution {
//public:
//	/**
//	* @param A: sorted integer array A which has m elements,
//	*           but size of A is m+n
//	* @param B: sorted integer array B which has n elements
//	* @return: void
//	*/
//	void mergeSortedArray(int A[], int m, int B[], int n) {
//		 write your code here
//		int i = m - 1, j = n - 1;
//		while (i >= 0 && j >= 0) {
//			if (A[i] <= B[j]) {
//				A[i + j + 1] = B[j];
//				--j;
//			}
//			else {
//				A[i + j + 1] = A[i];
//				--i;
//			}
//		}
//		while (j >= 0) {
//			A[j] = B[j];
//			--j;
//		}
//	}
//};
//
//int main(int argc, char *args[]) {
//	int A[5]{ 1, 2, 3, 0, 0};
//	int B[2]{ 4, 5 };
//	Solution solution1;
//	solution1.mergeSortedArray(A, 3, B, 2);
//	return 0;
//}