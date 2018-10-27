#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
	char firstUniqChar(string &str) {
		unordered_map<char, int> m;
		for (auto &c : str)
			++m[c];
		for (auto &c : str)
			if (m[c] == 1)
				return c;
	}
};

int main() {
	string s{ "hello world" };
	Solution solu;
	cout << solu.firstUniqChar(s);
	return 0;
}