//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_set>
//using namespace std;
//
// O(m^2) O(n^2)
//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		vector<int> interX;
//		for (int i = 0; i < nums1.size(); i++) {
//			for (int j = 0; j < nums2.size(); j++) {
//				bool flag = 0;
//				if (nums1[i] == nums2[j]) {
//					for (int k = 0; k < interX.size(); k++) {
//						if (nums1[i] == interX[k])
//							flag = true;
//					}
//					if (!flag)
//						interX.push_back(nums1[i]);
//				}
//			}
//		}
//		return interX;
//	}
//};
//
// O(m+n)
//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		vector<int> inter;
//		int p1 = 0, p2 = 0;
//		std::sort(nums1.begin(), nums1.end());
//		std::sort(nums2.begin(), nums2.end());
//		while ((p1 != nums1.size()) && (p2 != nums2.size())) {
//			if (nums1[p1] < nums2[p2]) {
//				p1++;
//			}
//			else if (nums1[p1] > nums2[p2]) {
//				p2++;
//			}
//			else if (nums1[p1] == nums2[p2]) {
//				if (inter.size() == 0) {
//					inter.push_back(nums1[p1]);
//				}
//				else {
//					if (inter[inter.size() - 1] != nums1[p1]) {
//						inter.push_back(nums1[p1]);
//					}
//				}
//				p1++;
//				p2++;
//			}
//		}
//		return inter;
//	}
//};
//
//
//
// Time:  O(m + n)
// Space: O(min(m, n))
//
// Hash solution.
//class Solution {
//public:
//    /**
//     * @param nums1 an integer array
//     * @param nums2 an integer array
//     * @return an integer array
//     */
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        if (nums1.size() > nums2.size()) {
//            return intersection(nums2, nums1);
//        }
//
//        unordered_set<int> lookup{nums1.cbegin(), nums1.cend()};
//
//        vector<int> result;
//        for (const auto& i : nums2) {
//            if (lookup.count(i)) {
//                result.emplace_back(i);
//                lookup.erase(i);
//            }
//        }
//
//        return result;
//    }
//};
//
//
// Time:  O(max(m, n) * log(max(m, n)))
// Space: O(1)
// Binary search solution.
//class Solution2 {
//public:
//    /**
//     * @param nums1 an integer array
//     * @param nums2 an integer array
//     * @return an integer array
//     */
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        if (nums1.size() > nums2.size()) {
//            return intersection(nums2, nums1);
//        }
//
//        sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());
//
//        vector<int> result;
//        auto it = nums2.cbegin();
//        for (const auto& i : nums1) {
//            it = lower_bound(it, nums2.cend(), i);
//            if (it != nums2.end() && *it == i) {
//                result.emplace_back(*it);
//                it = upper_bound(it, nums2.cend(), i);
//            }
//        }
//        
//        return result;
//    }
//};
//
//
// Time:  O(max(m, n) * log(max(m, n)))
// Space: O(1)
// Two pointers solution.
//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		vector<int> inter;
//		std::sort(nums1.begin(), nums1.end());
//		std::sort(nums2.begin(), nums2.end());
//		auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
//		while ((it1 != nums1.cend()) && (it2 != nums2.cend())) {
//			if (*it1 < *it2) {
//				++it1;
//			}
//			else if (*it1 > *it2) {
//				++it2;
//			}
//			else if (*it1 == *it2) {
//				if (inter.empty() ||  (inter.back() != *it1) )
//						inter.emplace_back(*it1);
//				++it1, ++it2;
//			}
//		}
//		return inter;
//	}
//};