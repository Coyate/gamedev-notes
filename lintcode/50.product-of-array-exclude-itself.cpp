#include <vector>
using namespace std;
class Solution {
public:
    vector<long long> productExcludeItself(vector<int> &nums) {
        if(nums.empty()) return {};
        vector<long long> b(nums.size());
        b.back() = 1;
        for(int i = b.size() - 1; i > 0; --i)
            b[i - 1] = b[i] * nums[i];
        long long s = 1;
        for(int i = 0; i < b.size() - 1; ++i) {
            s *= nums[i];
            b[i + 1] *= s;
        }
        return b;
    }
};