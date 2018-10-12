
class Solution {
public:
    int climbStairs(int n) {
		if (n <= 0) return 0;
		int a = 1, b = 1, c = 1;
		for (int i = 1; i < n; ++i)
			c = b + a, a = b, b = c;
		return c;
    }
};