#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <utility>
#include <set>
#include "linklist.h"
using namespace std;



class Solution {
public:
	ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
		if (!headA || !headB)
			return nullptr;
		auto a = headA, b = headB;
		auto ca = 1, cb = 1;
		while (a)
			a = a->next, ++ca;
		while (b)
			b = b->next, ++cb;
		a = headA, b = headB;
		while (ca > cb)
			a = a->next, --ca;
		while (cb > ca)
			b = b->next, --cb;
		while (a && b) {
			if (a == b)
				return a;
			a = a->next;
			b = b->next;
		}
	}
};


int main() {
	LinkList l1({ 1,2,3,4 });
	LinkList l2({ 0,9,8,7,6 });
	auto a = l1.head;
	while (a->next)
		a = a->next;
	a->next = l2.head;
	Solution solu;
	auto c = solu.getIntersectionNode(l1.head, l2.head);
	return 0;
}