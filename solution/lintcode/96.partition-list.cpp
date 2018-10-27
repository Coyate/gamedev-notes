// double head
class Solution {
public:
    ListNode * partition(ListNode * head, int x) {
        ListNode *d1 = new ListNode(0),  *d2 = new ListNode(0);
        ListNode *p = head, *p1 = d1, *p2 = d2;
        while(p) {
            if(p->val < x) {
                p1->next = p;
                p1 = p;
            } else {
                p2->next = p;
                p2 = p;
            }
            p = p->next;
        }
        p1->next = d2->next;
        p2->next = nullptr;
        return d1->next;
    }
};

// single head
class Solution {
public:
    ListNode * partition(ListNode * head, int x) {
        ListNode *d = new ListNode(0);
        d->next = head;
        ListNode *r = d, *s = d, *p = head;
        while(p) {
            if(p->val < x) {
                if(p != s->next) {
                    r->next = p->next;
                    p->next = s->next;
                    s->next = p;
                    p = r->next;
                } else {
                    r = p;
                    p = p->next;
                }
                s = s->next;
            } else {
                r = p;
                p = p->next;   
            }
        }
        return d->next;
    }
};