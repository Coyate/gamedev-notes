// Space O(1), Time O(n^2)
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
//	int maxSubArray(vector<int> nums) {
//		int maxSum = nums[0];
//		for (int i = 0; i != nums.size() - 1; ++i) {
//			int sum = nums[i];
//			for (int j = i + 1; j != nums.size(); ++j) {
//				sum += nums[j];
//				if (sum > maxSum)
//					maxSum = sum;
//			}
//		}
//		return maxSum;
//	}
//};
//
//int main(int argc, char *args[]) {
//	vector<int> test{ -2,2,-3,4,-1,2,1,-5,3 };
//	Solution solution1;
//	int result = solution1.maxSubArray(test);
//	cout << result << endl;
//	return 0;
//}
//
//
// Space O(1), Time O(n)
//class Solution {
//public:    
//    /**
//     * @param nums: A list of integers
//     * @return: A integer indicate the sum of max subarray
//     */
//    int maxSubArray(vector<int> nums) {
//		int maxSum = nums[0];
//		int sum = 0;
//		for (int j = 0; j != nums.size(); ++j) {
//			sum += nums[j];
//			if (sum > 0) {
//				if (sum > maxSum) {
//					maxSum = sum;
//				}
//			}
//			else {
//				sum = 0;
//			}
//		}
//		return maxSum;
//    }
//};
