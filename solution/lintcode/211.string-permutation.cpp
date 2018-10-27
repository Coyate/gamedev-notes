#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <unordered_set>
#include <set>
#include <Windows.h>
using namespace std;

class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
		if (A.size() != B.size())
			return false;
		if (A.empty() && B.empty())
			return true;
		if (A.empty() || B.empty())
			return false;
		multiset<char> setA(A.begin(), A.end());
		multiset<char> setB(B.begin(), B.end());
		return setA == setB;
    }
};

class Solution {
public:
    bool Permutation(string &A, string &B) {
        if(A.size() != B.size())
            return false;
		return is_permutation(A.begin(), A.end(), B.begin());
    }
};