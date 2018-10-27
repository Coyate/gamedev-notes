#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int> &A, int target) {
        auto b = A.begin(), e = A.end();
        int t = target;
        if(find(b, e, t) == e)
            return {-1, -1};
        return {lower_bound(b, e, t) - b, upper_bound(b, e, target) - b - 1};
    }
    // Manual lower_bound && upper_bound
    vector<int> searchRange(vector<int> &A, int target) {
        if(find(A.begin(), A.end(), target) == A.end())
            return {-1, -1};
        int l = 0, r = A.size() - 1, m = 0;
        vector<int> vi(2);
        while(l <= r) {
            m = (l + r) >> 1;
            if (A[m] == target) {
                    if (m == 0 || A[m - 1] != target)
                        break;
                    else {
                        r = m - 1;
                        continue;
                    }
            } else if(A[m] < target) {
                l = m + 1;
            } else
                r = m - 1;
        }
        vi[0] = m;
        l = 0; r = A.size() - 1;
        while(l <= r) {
            m = (l + r) >> 1;
            if (A[m] == target) {
                    if (m == A.size() - 1 || A[m + 1] != target)
                        break;
                    else {
                        l = m + 1;
                        continue;
                    }
                        
            } else if(A[m] < target) {
                l = m + 1;
            } else
                r = m - 1;
        }
        vi[1] = m;
        return vi;
    }
};

