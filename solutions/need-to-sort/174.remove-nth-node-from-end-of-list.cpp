// 输入一个链表，输出该链表中倒数第k个结点

#include <vector>
#include <iostream>
#include <algorithm>
#include "linklist.h"
using namespace std;

//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//}; 


class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
		auto p = head;
		auto pn = p;
		for (int i = 0; i != n; ++i)
			if (p)
				p = p->next;
			else
				return head;
		auto pre = pn;
		if (p) {
			p = p->next;
			pn = pn->next;
		}
		while (p) {
			p = p->next;
			pn = pn->next;
			pre = pre->next;
		}
		if (pn == pre) {
			pre = pre->next;
			delete pn;
			pn = nullptr;
			return pre;
		}
		else {
			pre->next = pn->next;
			delete pn;
		}
		return head;
    }
};

int main() {
	vector<vector<int>> vvi{
		{},
	{ 1 },
	{1, 2, 3, 4, 5},
	{ 1,2,3,4,5,6,7,8,9,10 }
	};

	Solution solu;
	for (auto &vi : vvi) {
		LinkList LL(vi);
		cout << LL.head << endl;
		ListNode* p = solu.removeNthFromEnd(LL.head, 2);
		cout << LL.head << endl;
		cout << endl;
	}
	return 0;
}

