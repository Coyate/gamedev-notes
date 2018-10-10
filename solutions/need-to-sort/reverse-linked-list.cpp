//// Time: O(n), Space: O(1)
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
//
//class Solution {
//public:
//    /*
//    * @param head: n
//    * @return: The new head of reversed linked list.
//    */
//    ListNode * reverse(ListNode * head) {
//        // write your code here
//        ListNode l{ 0 };
//        while (head != nullptr) {
//            auto tmp = head->next;
//            head->next = l.next;
//            l.next = head;
//            head = tmp;
//        }
//        return l.next;
//    }
//};