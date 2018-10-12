//
//class Solution {
//public:
//	/**
//	*@param A: A list of integers
//	*@param elem: An integer
//	*@return: The new length after remove
//	*/
//	int removeElement(vector<int> &A, int elem) {
//		// write your code here
//		bool flag;
//		for (auto it = A.begin(); it != A.end(); it += 1 * flag) {
//			flag = true;
//			if (*it == elem) {
//				it = A.erase(it);
//				flag = false;
//			}
//		}
//		return A.size();
//	}
//};