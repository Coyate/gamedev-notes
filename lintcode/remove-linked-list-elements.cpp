//// two pointer
//// Time: O(n), Space: O(1)
//
//class Solution {
//public:
//	/*
//	* @param head: a ListNode
//	* @param val: An integer
//	* @return: a ListNode
//	*/
//	ListNode * removeElements(ListNode * head, int val) {
//		// write your code here
//		ListNode l{ 0 };
//		l.next = head;
//		auto p = &l, q = l.next;
//		while (q) {
//			if (q->val == val) {
//				p->next = q->next;
//				delete q;
//			}
//			else
//			{
//				p = q;
//			}
//			q = q->next;
//		}
//		return l.next;
//	}
//};