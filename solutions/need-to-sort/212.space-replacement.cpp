/*!
*	@brief 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <memory>
using namespace std;

class Solution {
public:
	// 在有足够静态空间的情况下
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;
		int count = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] == ' ')
				++count;
		}

		int j = length - 1 + 2 * count;
		for (int i = length - 1; i >= 0; --i) {
			if (str[i] == ' ') {
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
			}
			else {
				str[j--] = str[i];
			}
		}

	}
};

// lintcode
class Solution2 {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
		if (length <= 0)
			return 0;
		std::string str{string};
		while (str.find(' ') != std::string::npos) {
			str.replace(str.find(' '), 1, "%20");
		}
		for (int i = 0; i < str.length(); ++i) {
			string[i] = str[i];
		}
		string[str.length()] = '\0';
		return str.size();
	}
};

int main(int argc, char *argv[]) {


	char c[100];
	strcpy_s(c, 16, "hello minecraft");

	Solution solu;
	solu.replaceSpace(c, 15);
	cout << c << endl;
	system("PAUSE");
	return 0;
}
