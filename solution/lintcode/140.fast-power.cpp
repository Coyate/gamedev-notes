#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


class Solution {
public:
	/**
	* @param a: A 32bit integer
	* @param b: A 32bit integer
	* @param n: A 32bit integer
	* @return: An integer
	*/
	int fastPower(int a, int b, int n) {
		if (a == 0 || n < 0 || b == 0)
			return 0;
		if (n == 0)
			return 1 % b;
		if (n == 1)
			return a;
		long long hf = fastPower(a, b, n / 2) % b;
		hf = hf * hf % b;
		return n % 2 == 1 ? hf * a % b : hf;
	}
};

int main() {
	Solution solu;
	cout << solu.fastPower(109, 10000007, 1000001) << endl;
	cout << solu.fastPower(31, 1, 0) << endl;
	cout << solu.fastPower(2, 3, 31) << endl;
	cout << solu.fastPower(100, 1000, 1000) << endl;
	cout << solu.fastPower(2, 3, 0) << endl;
	cout << solu.fastPower(2, 3, -31) << endl;
	cout << solu.fastPower(0, 1, 31) << endl;
	cout << solu.fastPower(2, 3, 10) << endl;
	system("PAUSE");
	return 0;
}