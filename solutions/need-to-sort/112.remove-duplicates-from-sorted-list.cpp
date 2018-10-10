#include "Link_list.h"
class Solution {
public:
	ListNode * deleteDuplicates(ListNode * head) {
		if(!head) return head;
		ListNode *a = head, *b = a->next, *m, *n;
		while (b) {
			if (a->val != b->val) {
				a = a->next;
				b = b->next;
			}
			else {
				while (b && a->val == b->val)
					b = b->next;
				if (a != b) {
					m = a->next;
					a->next = b;
					while (m != b) {
						n = m->next;
						delete m;
						m = n;
					}
				}
			}
		}
		return head;
	}

	// 不删除节点，不推荐这样写
	ListNode * deleteDuplicates(ListNode * head) {
		if(!head) return head;
		ListNode *p = head;
		while (p) {
			while(p->next && p->val == p->next->val)
			    p->next = p->next->next;
			p = p->next;
		}
		return head;
	}

};