#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &A) {
        int k = 0;
        for(auto i : A)
            k ^= i;
        return k;
    }
    
    int singleNumber2(vector<int> &A) {
       sort(A.begin(), A.end());
       int i = 0;
       while(i < A.size() - 1) {
            if( A[i] != A[i+1])
                return A[i];
            i+=2;
       }
       return A[i];
    }
    
    int singleNumber3(vector<int> &A) {
       set<int> s;
       for(auto i : A) {
           auto t = s.find(i);
           if(t != s.end())
                s.erase(t);
           else
                s.insert(i);
           
       }
       return *s.begin();
    }

};