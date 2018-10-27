#include <vector>
using namespace std;


class Solution {
public:
    vector<int> singleNumberIII(vector<int> &A) {
        unordered_map<int, int> m;
        for(auto i : A)
            m[i] += 1;
        vector<int> v;
        for(auto const &i : m)
            if(i.second == 1)
                v.push_back(i.first);
        return v;
    }
    // 位运算
    vector<int> singleNumberIII2(vector<int> &A) {
        int m, n, c, s = 0;
        m = n = c = s;
        for(int i : A)
            s ^= i;
        while(!(s & 0x01))
            s >>= 1, ++c;
        s = 0x01;
        while(c)
            s <<= 1, --c;
        for(int i : A)
            if(i & s)
                m ^= i;
            else
                n ^= i;
        for(int i : A) {
            if(i == m)
                return {m , n};
            if(i == n)
                return {n , m};
        }
    }
};