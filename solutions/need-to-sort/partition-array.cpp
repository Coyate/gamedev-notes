//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    int partitionArray(vector<int> &nums, int k) {
//        // write your code here
//        int p1 = 0, p2 = nums.size() - 1;
//        while (p1 <= p2) {
//            if (nums[p1] < k) {
//                ++p1;
//            } else if (nums[p2] >= k) {
//                --p2;
//            } else {
//                swap(nums[p1++], nums[p2--]); 
//            }
//        }
//        return p1;
//    }
//};
//
//
///*int main (int argc, char *args[]) {
//    vector<int> s1{9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9};
//    int ho;
//    Solution solution1;
//    ho = solution1.partitionArray(s1, 9);
//    cout << ho << endl;
//    return 0;
//}           */                                    