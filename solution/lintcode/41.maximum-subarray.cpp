#include <vector>
using namespace std;

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
    	int maxSum = nums[0];
		int sum = 0;
		for (int j = 0; j != nums.size(); ++j) {
			sum += nums[j];
			if (sum > 0) {
				if (sum > maxSum)
					maxSum = sum;
			}
			else
				sum = 0;
		}
		return maxSum;
    }
};