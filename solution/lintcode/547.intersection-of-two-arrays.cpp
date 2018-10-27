#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        vector<int> vi;
        auto a = nums1.begin(), b = nums1.end(), c = nums2.begin(), d = nums2.end();
        sort(a, b); 
        sort(c, d);
        set_intersection(a, b, c, d, back_inserter(vi));
        vi.erase(unique(vi.begin(), vi.end()), vi.end());
        return vi;
    }

    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        vector<int> vi;
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(vi));
        return vi;
    }
};