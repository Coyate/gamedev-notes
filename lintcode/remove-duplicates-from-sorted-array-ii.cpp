//// Space: O(1) Time: O(n) 
//class Solution {
//public:
//	/**
//	* @param A: a list of integers
//	* @return : return an integer
//	*/
//	int removeDuplicates(vector<int> &nums) {
//		// write your code here
//		if (nums.empty())
//			return 0;
//		auto it = nums.begin();
//		auto it2 = it + 1;
//		auto it3 = it2 + 1;
//		while (it3 != nums.end()) {
//			if (*it == *it2 && *it2 == *it3) {
//                // iterator mention
//				it3 = nums.erase(it2);
//				it2 = it3;
//				it3++;
//			}
//			else {
//				it++;
//				it2++;
//				it3++;
//			}
//		}
//		return nums.size();
//	}
//};