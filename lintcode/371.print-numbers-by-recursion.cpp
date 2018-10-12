#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;



class Solution {
public:
	/**
	* @param n: An integer
	* @return: An array storing 1 to the largest number with n digits.
	*/
	vector<int> numbersByRecursion(int n) {
		if (n < 1)
			return {};
		vector<int> result;
		large(result, stoi(string(n, '9')), 0);
		return result;
	}

	void large(vector<int> &vi, int n, int i) {
		if (i != n) {
			vi.push_back(i);
			large(vi, n, ++i);
		}
		return;
	}

// non-Recur
    vector<int> numbersByRecursion2(int n) {
		if (n < 1) return {};
		vector<int> r;
        for(int i = 1; i <= stoi(string(n, '9')); ++i)
            r.push_back(i);
		return r;
    }

};


int main() {
	vector<int> vi{
		-1, // Negative test
		0,	// Bound test
		1, 2, 3 // Function test
	};
	Solution solu;
	for (auto i : vi) {
		vector<int> result = solu.numbersByRecursion(i);
		for (auto r : result) {
			cout << r << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}