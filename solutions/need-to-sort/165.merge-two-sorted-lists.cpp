//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

#include <vector>
#include <iostream>
#include <algorithm>
#include "linklist.h"
using namespace std;

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
	// 2100ms Recur
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode* merged = nullptr;
		if (l1->val <= l2->val) {
			merged = l1;
			merged->next = mergeTwoLists(merged->next, l2);
		}
		else {
			merged = l2;
			merged->next = mergeTwoLists(l1, merged->next);
		}
		return merged;
    }

    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
	// 2323ms
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode *dummy = new ListNode(-1);
		dummy->next = nullptr;
		ListNode *p = nullptr;
		ListNode *merged = dummy;
		while (l1 || l2) {
			if (l1 && l2) {
				if (l1->val <= l2->val) {
					p = l1;
					l1 = l1->next;
				}
				else {
					p = l2;
					l2 = l2->next;
				}
			}
			else {
				if (l1) {
					p = l1;
					l1 = l1->next;
				}
				else {
					p = l2;
					l2 = l2->next;
				}
			}
			merged->next = p;
			merged = merged->next;
			merged->next = nullptr;
		}
		p = dummy->next;
		delete dummy;
		return p;
    }
};


int main() {
	vector<vector<int>> vvi{
	{},
	{1},
	{1,3,6,8,13,17,19,23,27},
	{1,2,3,4,5,6,7,8,9,10}
	};
	Solution solu;
	for (auto &vi : vvi) {
		for (auto &vi2 : vvi) {
			LinkList L1(vi);
			LinkList L2(vi2);
			cout << "L1 : " << L1.head << endl;
			cout << "L2 : " << L2.head << endl;
			ListNode* p = solu.Merge(L1.head, L2.head);
			cout << "Merged : " << p << endl;
			L1.head = p;
			L2.head = nullptr;
			cout << endl;
		}
	}
	return 0;
}

