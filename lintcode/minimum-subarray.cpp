//// Time : O(n^2) Space: O(1)
//
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
//	* @param nums: a list of integers
//	* @return: A integer denote the sum of minimum subarray
//	*/
//	int minSubArray(vector<int> nums) {
//		// write your code here
//		int sum = nums[0];
//		for (int i = 0; i < nums.size(); i++) {
//			int thissum = 0;
//			for (int j = i; j < nums.size(); j++) {
//				thissum += nums[j];
//				if (thissum < sum) {
//					sum = thissum;
//				}
//			}
//		}
//		return sum;
//	}
//};
//
////int main(int argc, char *args[]) {
////	vector<int> test{ 1, -1, -2, 1};
////	Solution solution1;
////	int result = solution1.minSubArray(test);
////	cout << result << endl;
////	return 0;
////}
//
//
//
//// Space: O(1), Time: persudo O(n)
//
//class Solution {
//public:
//	/**
//	* @param nums: a list of integers
//	* @return: A integer denote the sum of minimum subarray
//	*/
//	int minSubArray(vector<int> nums) {
//		// write your code here
//		int sum = nums[0];
//		for (int i = 0; i < nums.size(); i++) {
//			int thissum = 0;
//			for (int j = i; j < nums.size(); j++) {
//				thissum += nums[j];
//				if (thissum < sum) {
//					sum = thissum;
//				}
//				if (thissum >= 0) {
//					i = j;
//					break;
//				}
//			}
//		}
//		return sum;
//	}
//};
//
//// Space: O(1), Time: O(n)
//
//class Solution {
//public:
//	/**
//	* @param nums: a list of integers
//	* @return: A integer denote the sum of minimum subarray
//	*/
//	int minSubArray(vector<int> nums) {
//		// write your code here
//		int sum = nums[0], thissum = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			thissum += nums[i];
//			if (thissum < sum) {
//				sum = thissum;
//			}
//			if (thissum >= 0) {
//				thissum = 0;
//			}
//		}
//		return sum;
//	}
//};