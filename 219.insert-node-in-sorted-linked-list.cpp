class Solution {
public:

    ListNode * insertNode(ListNode * head, int val) {
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *p = dummy;
        while(p->next && p->next->val < val)
            p = p->next;
        ListNode *n = new ListNode(val);
        n->next = p->next;
        p->next = n;
        return dummy->next;
    }

    ListNode * insertNode(ListNode * head, int val) {
        if(!head)
            return new ListNode(val);
        ListNode *p = head;
        while(p) {
            if(p->val > val || !p->next) {
                ListNode *n = new ListNode(val);
                n->next = p->next;
                p->next = n;
                if(val < p->val)
                    swap(n->val, p->val);
                break;
            }
            p = p->next;
        }
        return head;
    }
};