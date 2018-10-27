#include <string>
#include <algorithm>
#include <stringstream>
using namespace std;


class Solution {
public:
    string reverseWords(string &s) {
		stringstream m(s);
		s.clear();
		string t;
		while (m >> t)
			t += ' ', s.insert(s.begin(), t.begin(), t.end());
		if(!s.empty())
			s.erase(s.end() - 1);	
		return s;
    }
};