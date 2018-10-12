#include "list.h"
class Solution {
 public:
     ListNode * reverseBetween(ListNode * head, int m, int n) {
		 ListNode l;
		 l.next = head;
		 ListNode * p = &l;
		 int i;
		 for (i = 0; i < m - 1; i++)
			 p = p->next;
		 auto h = p;
		 p = p->next;
		 auto p2 = p->next;
		 for (i = m; i < n; i++) {
			 p->next = p2->next;
			 p2->next = h->next;
			 h->next = p2;
			 p2 = p->next;
		 }
		 return l.next;
	 }
 };