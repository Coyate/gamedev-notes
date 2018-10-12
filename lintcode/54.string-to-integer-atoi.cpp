#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;


class Solution {
public:
	int atoi(string &str) {
		if (str.empty())
			return 0;

		int i = 0;
		while (i < str.size() && str[i] == ' ')
			++i;

		int s = 0;
		if (i < str.size()) {
			s = str[i] == '-' ? -1 : str[i] == '+' ? -2 : 0;
			if (str[i] == '+' || str[i] == '-')
				++i;

			if (s != 0 && i < str.size() && !isdigit(str[i]))
				return 0;
		}
		else
			return 0;


		long long r = 0;
		for (; i != str.size(); ++i) {
			if (str[i] == '.')
				break;
			if (!isdigit(str[i]))
				return s == -1 ? -r / 10 : r / 10;
			r += str[i] - '0';
			r *= 10;
		}
		r /= 10;

		float f = 0;
		if (i != str.size() && i + 1 == str.size())
			return 0;
		++i;
		while (i < str.size()) {
			if (!isdigit(str[i]))
				return 0;
			f += str[i] - '0';
			f /= 10;
			++i;
		}

		if (r < 0)
			return s == -1 ? INT_MIN : INT_MAX;

		r += int(f);
		if (s == -1)
			r = -r;

		return r > INT_MAX ? INT_MAX : r < INT_MIN ? INT_MIN : r;
	}


    int atoi2(string &str) {
    	if (str.empty())
		    return 0;
        str.erase(0, str.find_first_not_of(' '));

		int i = 0;
		bool s = str[i] == '-';
		if (str[i] == '+' || str[i] == '-')
			++i;

		long long r = 0;
		while(i < str.size()) {
	    	if (!isdigit(str[i])) 
			    return s ? -r / 10 : r / 10;
            r += str[i] - '0';
			if (r < 0)
			    return s ? INT_MIN : INT_MAX;
			r *= 10;
			++i;
		}
        r = r / 10;
		if (s) r = -r;
		return r > INT_MAX ? INT_MAX : r < INT_MIN ? INT_MIN : r;
    }

};

int main() {
	vector<string> vs{
		{ "   " },
		{ "    - "},
		{"   -5211314"},
		{},
		{"0"},
		{"1"},
		{"-1"},
		{"10"},
		{"+0.1"},
		{"+."},
		{"-0.8"},
		{"2147483647"},
		{"2147483648"},
		{"2147483647.4"},
		{"2147483646.5"},
		{"2147483646.6"},
		{"-2147483648"},
		{ "-2147483647.8" },
		{"123123123123123"},
		{ "1234567890123456789012345678901234567890" } // long long
	};
	Solution solu;
	for (auto &s : vs) {
		cout << s << " : " << solu.atoi(s) << endl;
	}

	system("PAUSE");
	return 0;
}