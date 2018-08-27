class Solution {
public:
    static Solution* getInstance() {
			static Solution solu;
			return &solu;
		}
};