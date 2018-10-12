//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * @param nums: The integer array.
//     * @param target: Target number to find.
//     * @return: The first position of target. Position starts from 0. 
//     */
//    int binarySearch(vector<int> &array, int target) {
//         write your code here
//        auto begin = array.begin();
//        auto end = --array.end();
//        auto middle = array.begin();
//        while(begin < end && *middle != target) {
//            middle = begin + (end - begin) / 2;
//            if(*middle < target) {
//                begin = middle + 1 ;
//            } else {
//                end = middle;
//            }
//        } 
//        if(begin <= end && *middle == target) {
//            while(*middle == target)
//                --middle;
//            return middle + 1 - array.begin();
//        }
//        return -1;
//    }
//
//
//};
//
//int main (int argc, char *args[]) {
//    // vector<int> s1{1,4,4,5,7,7,8,9,9,10};
//    vector<int> s1{4,5,9,9,12,13,14,15,15,18};
//    int ho;
//    Solution solution1;
//    ho = solution1.binarySearch(s1, 10);
//    cout << ho << "+1" << endl;
//    return 0;
//}                                               