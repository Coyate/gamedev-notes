#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int singleNumberII(vector<int> &A) {
        unordered_map<int, int> m;
        for(auto i : A)
            m[i] += 1;
        vector<int> v;
        for(auto const &i : m)
            if(i.second == 1)
                return i.first;
    }

// 对 ones操作， ones = ones ^ A[i] & (~twos)意思是把A[i] 计入到出现一次的情况里，但是有可能这个数已经出现过两次，所以要排除两次情况
// 对 twos操作， twos = twos ^ A[i] & (~ones) 把A[i] 计入到两次情况，如果第三次出现了，自然消掉了，如果第二次出现，那么就计入，如果是第一次出现，不计入，这个过程通过和ones的非相交来控制

    int singleNumberII(vector<int> &A) {
        int ones = 0;
        int twos = 0;
		for (auto i : A)
		{
            ones = (ones ^ i) & (~ twos);
            twos = (twos ^ i) & (~ ones);
		}
		return ones;
	}
};