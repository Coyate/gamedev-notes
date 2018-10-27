//Count how many 1 in binary representation of a 32 - bit integer.
//Example
//Given 32, return 1
//Given 5, return 2
//Given 1023, return 9

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
	/*
	* @param num: An integer
	* @return: An integer
	*/
	// 69ms	
	int countOnes(int num) {
		// write your code here
		int result = 0;
		while (num) {
			num = num & (num - 1);
			++result;
		}
		return result;
	}

	// 282ms
	int countOnes(int num) {
		int r = 0;
		while (num) {
			num &= (num - 1);
			++r;
		}
		return r;
	}
};

int main() {
	Solution solu;
	vector<int> vi{
		-1, -0, 0, 1, 5, 31, 32, 63, 127, 255, 511, 1023,
	};
	for (auto i : vi) {
		cout << i << " \t: " << bitset<sizeof(int) * 8>(i) << " contains " << solu.countOnes(i) << " number 1 " << endl;
	}
	return 0;
}

