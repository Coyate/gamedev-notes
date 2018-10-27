#include <string>
using namespace std;
class Solution {
public:
    void rotateString(string &str, int offset) {
        if(!str.empty()) {
            offset = offset % str.size();
            if(offset < 0)
                offset += str.size();
            auto b = str.begin(), e = str.end();
            reverse(b, e);
            reverse(b, b + offset);
            reverse(b+offset, e); 
        }
    }
};