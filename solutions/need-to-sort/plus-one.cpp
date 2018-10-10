//// Space : O(1), Time: O(n)
//class Solution {
//public:
//	/*
//	* @param digits: a number represented as an array of digits
//	* @return: the result
//	*/
//	vector<int> plusOne(vector<int> digits) {
//		// write your code here
//		if (digits.size() != 0) {
//			int c = 1;
//			int i = digits.size() - 1;
//			while (c && i >= 0) {
//				if ((++digits[i]) >= 10) {
//					digits[i] = digits[i] - 10;
//					i--;
//				}
//				else
//				{
//					c = 0;
//				}
//			}
//			if (c && i < 0) {
//				digits.insert(digits.begin(), c);
//			}
//		}
//		return digits;
//	}
//};