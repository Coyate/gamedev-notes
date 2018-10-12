// Space: O(1), Time: O(nlog(n))
//class Solution {
//public:
//	/**
//	* @param intervals: interval list.
//	* @return: A new interval list.
//	*/
//	static bool comp(const Interval &a, const Interval &b)
//	{
//		if (a.start != b.start)
//			return a.start < b.start;
//		else
//			return a.end < b.end;
//	}
//
//	vector<Interval> merge(vector<Interval> &intervals) {
//		 write your code here
//		sort(intervals.begin(), intervals.end(), comp);
//		bool flag;
//		for (auto it1 = intervals.begin(); intervals.end() - it1 > 1; it1 += 1 * flag) {
//			auto it2 = it1 + 1;
//			flag = true;
//			if (it1->end >= it2->start)
//			{	
//			    if(it2->end > it1->end)
//					it1->end = it2->end;
//				intervals.erase(it2);
//				flag = false;
//			}
//		}
//		return intervals;
//	}
//};