//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * @param A and B: sorted integer array A and B.
//     * @return: A new sorted integer array
//     */
//    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
//        // write your code here
//        vector<int> result;
//        auto it1 = A.cbegin(), it2 = B.cbegin();
//        while (it1 != A.cend() || it2 != B.cend()) {
//            if (it1 != A.cend() && (it2 == B.cend() || *it1 <= *it2)) {
//                result.emplace_back(*it1);
//                ++it1;
//            }
//            if (it2 != B.cend() && (it1 == A.cend() || *it1 > *it2)) {
//                result.emplace_back(*it2);
//                ++it2; 
//            }
//        }
//        return result;
//    }
//};
//
//
///*int main (int argc, char *args[]) {
//    vector<int> s1{1, 2, 3, 4};
//    vector<int> s2{2, 4, 5, 6};
//    vector<int> ho;
//    Solution solution1;
//    ho = solution1.mergeSortedArray(s1, s2);
//    return 0;
//}       */                                        