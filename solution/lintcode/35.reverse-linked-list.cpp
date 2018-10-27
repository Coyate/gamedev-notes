// 输入一个链表，反转链表后，输出链表的所有元素。

#include <vector>
#include <iostream>
#include <algorithm>
#include "linklist.h"
using namespace std;

class Solution {
public:
	ListNode * ReverseList(ListNode* pHead) {
		if (!pHead)
			return nullptr;

		auto dummy = new ListNode(-1);
		dummy->next = nullptr;

		auto p = pHead;
		while (p) {
			auto temp = p->next;
			p->next = dummy->next;
			dummy->next = p;
			p = temp;
		}
		p = dummy->next;

		delete dummy;
		return p;
	}

    ListNode * reverse(ListNode * head) {
		if (!head)
			return nullptr;
		auto d = new ListNode();
        auto p = head;
		while (p) {
			auto t = p->next;
			p->next = d->next;
			d->next = p;
			p = t;
		}
		p = d->next;
		delete d;
		return p;
    }
};

int main() {
	vector<vector<int>> vvi{
	{},
	{1},
	{1,2,3,4,5,6,7,8,9,10}
	};
	Solution solu;
	for (auto &vi : vvi) {
		LinkList LL(vi);
		ListNode* p = solu.ReverseList(LL.head);
		cout << p << endl;
	}
	return 0;
}

