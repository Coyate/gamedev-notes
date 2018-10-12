//// two pointer
//// Space: O(1), Time: O(n)
//class Solution {
//public:
//	/**
//	* @param nums: a vector of integers
//	* @return: nothing
//	*/
//	void partitionArray(vector<int> &nums) {
//		// write your code here
//		int l = 0, r = nums.size() - 1;
//		while (l < r) {
//			if (nums[l] & 1) {
//                l++;
//            } else if (!(nums[r] & 1)) {
//                r--;
//            } else {
//                swap(nums[l], nums[r]);
//            }
//		}
//	}
//};