class Solution {
public:
    // Compelete backpack, O(VN), O(V)
    string isBuild(int x) {
        vector<bool> v(x + 1);
        v[0] = true;
        int b[] = {3, 7};
        for(int i = 0; i < 2; ++i)
            for(int j = b[i]; j <= x; ++j)
                if(!v[j] && v[j - b[i]])
                    v[j] = true;
        return v[x]?"YES":"NO";
    }

    // O(log_3(x))
    string isBuild(int x) {
        for(int i = 0; i < x / 3; ++i) {
            int k = x - 3 * i;
            if(!(k % 7) || !(k % 3))
                return "YES";
        }
        return "NO";
    }

    string isBuild(int x) {
        int i = x % 7;
        return !(i % 3) || !((i + 7) % 3) || !(x % 3)? "YES" : "NO";
    } 
};