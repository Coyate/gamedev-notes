//// Space: O(1) Time: O(n) 
//class Solution {
//public:
//    /**
//     * @param A: a list of integers
//     * @return : return an integer
//     */
//    int removeDuplicates(vector<int> &nums) {
//		// write your code here
//		if(nums.empty())
//		    return 0;
//		auto it = nums.begin();
//		auto it2 = it + 1;
//		while (it2 != nums.end()) {
//			if (*it == *it2) {
//				it2 = nums.erase(it2);
//			}
//			else {
//				it++;
//				it2++;
//			}
//		}
//		return nums.size();
//    }
//};