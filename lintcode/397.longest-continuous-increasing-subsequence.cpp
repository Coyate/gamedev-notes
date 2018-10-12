class Solution {
public:
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
    	if(A.empty())
    	    return 0;
    	int r = 1, a = 1, d = 1;
    	for (int i = 1; i < A.size(); ++i) {
    		if (A[i] > A[i - 1]) {
    		    ++a;
    		    d = 1;
    		} else if (A[i] < A[i - 1]){
    		    ++d;
    		    a = 1;
    		} else {
    			a = 1;
    			d = 1;
    		}
    		r = max(r, max(a, d));
    	}
    	return r;
    }
};