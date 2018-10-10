//// Time: O(1)
//// Space: O(n)
//
//
//// Definition of ListNode
//
//class ListNode {
//public:
//    int val;
//    ListNode *next;
//
//    ListNode(int val) {
//        this->val = val;
//        this->next = NULL;
//    }
//};
//
//
//class Solution {
//public:
//    ListNode * reverseBetween(ListNode * head, int m, int n) {
//        // write your code here
//        ListNode l{ 0 };
//        l.next = head;
//        ListNode * p = &l;
//        int i;
//        for (i = 0; i < m - 1; i++) {
//            p = p->next;
//        }
//        auto head2 = p;
//        p = p->next;
//        auto p2 = p->next;
//        for (i = m; i < n; i++) {
//            p->next = p2->next;
//            p2->next = head2->next;
//            head2->next = p2;
//            p2 = p->next;
//        }
//        return l.next;
//    }
//};
