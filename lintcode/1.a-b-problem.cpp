class Solution {
public:
    // 位操作，同或结果是需要进位的位置，异或结果是不需要进位的位置
    int aplusb(int a, int b) {
        int s,c;
        while(b != 0) {
            s = a ^ b;
            c = (a & b) << 1;
            a = s, b = c;
        }
        return a;
    }
};