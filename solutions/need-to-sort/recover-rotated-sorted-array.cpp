//// Rabbish Method
//// Time O(n), Space O(n)
//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdio>
//#include <cctype>
//using namespace std;
//
//class Solution {
//public:
//	void recoverRotatedSortedArray(vector<int> &nums) {
//		// write your code here
//		if (nums.empty())
//			return;
//
//		int k = 0;
//		while (k < nums.size() - 1) {
//			if (nums[k] > nums[k + 1])
//				break;
//			k++;
//		}
//
//		if (k == nums.size() - 1)
//			return;
//		vector<int> temp = nums;
//		
//		for (int i = 0; i < nums.size(); i++) {
//			if (i < nums.size() - 1 - k)
//				nums[i] = temp[i + k + 1];
//			else
//				nums[i] = temp[i + k + 1 - nums.size()];
//		}
//		return;
//	}
//};
//
//
//
//
////int main(int argc, char *args[]) {
////	vector<int> test{ 4, 5, 1, 2, 3 };
////	Solution solution1;
////	solution1.recoverRotatedSortedArray(test);
////	for (auto c : test) {
////		cout << c << endl;
////	}
////	return 0;
////}
//
//// Reverse Method
//// Time O(n), Space O(1)
//
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
//	void recoverRotatedSortedArray(vector<int> &nums) {
//		// write your code here
//		if (nums.empty())
//			return;
//
//		int k = 0;
//		while (k < nums.size() - 1) {
//			if (nums[k] > nums[k + 1])
//				break;
//			k++;
//		}
//
//		if (k == nums.size() - 1)
//			return;
//
//		for (int i = 0; i < (k + 1) / 2; i++) {
//			swap(nums[i], nums[k - i]);
//		}
//		for (int i = 0; i < (nums.size() - k - 1) / 2; i++) {
//			swap(nums[k + 1 + i], nums[nums.size() - 1 - i]);
//		}
//		for (int i = 0; i < nums.size() / 2; i++) {
//			swap(nums[i], nums[nums.size() - 1 - i]);
//		}
//		return;
//	}
//};
//
//
//int main(int argc, char *args[]) {
//	vector<int> test{ 4, 5, 6, 7, 1, 2, 3 };
//	Solution solution1;
//	solution1.recoverRotatedSortedArray(test);
//	for (auto c : test) {
//		cout << c << endl;
//	}
//	return 0;
//}
//
//// Reverse Method
//// Time O(n), Space O(1)
//
//class Solution {
//public:
//	void recoverRotatedSortedArray(vector<int> &nums) {
//		int k = findMidPoint(nums) - 1;
//
//		for (int i = 0; i < (k + 1) / 2; i++) {
//			swap(nums[i], nums[k - i]);
//		}
//		for (int i = 0; i < (nums.size() - k - 1) / 2; i++) {
//			swap(nums[k + 1 + i], nums[nums.size() - 1 - i]);
//		}
//		for (int i = 0; i < nums.size() / 2; i++) {
//			swap(nums[i], nums[nums.size() - 1 - i]);
//		}
//		/*
//		reverse(nums.begin(), nums.begin() + k);
//		reverse(nums.begin() + k, nums.end());
//		reverse(nums.begin(), nums.end());
//		*/
//	}
//
//	int findMidPoint(vector<int> &nums) {
//		int left = 0;
//		int right = nums.size() - 1;
//
//		while (left < right && nums[left] >= nums[right]) {
//			int middle = (left + right) / 2;
//			if (nums[middle] > nums[left]) {
//				left = middle;
//			}
//			else if (nums[middle] < nums[right])
//			{
//				right = middle;
//			}
//			else {
//				++left;
//			}
//		}
//		return left;
//	}
//};