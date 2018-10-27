#include <vector>
#include <multiset>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> medianII(vector<int> &nums) {
		multiset<int> q;
		vector<int> v;
		for (auto i : nums) {
			q.insert(i);
			auto beg = q.begin();
			int s = (q.size() - 1) / 2;
			while (s-- > 0)
				++beg;
			v.push_back(*beg);
		}
		return v;
    }

    vector<int> medianII(vector<int> &nums) {
       multiset<int, greater<int>> p;
       multiset<int> q;
       vector<int> v;
       for(auto i : nums) {
           if(p.empty() || p.size() < q.size() + 1) {
               q.insert(i);
               p.insert(*q.begin());
               q.erase(q.begin());
           } else {
               p.insert(i);
               q.insert(*p.begin());
               p.erase(p.begin());
           }
           v.push_back(*p.begin());
       }
       return v;
    }
};