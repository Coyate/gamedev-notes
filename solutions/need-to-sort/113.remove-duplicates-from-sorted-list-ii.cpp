#include "linklist.h"
class Solution {
public:
    ListNode * deleteDuplicates(ListNode * head) {
        ListNode* d = new ListNode(-1), *a = head, *b;
        ListNode* p = d;
        while(a) {
            b = a->next;
            if(b && a->val == b->val) {
                while(b && a->val == b->val) {
                    a->next = b->next;
                    delete b;
                    b = a->next;
                }
                delete a;
                a = b;
            } else {
                p->next = a;
                p = p->next;
                a = a->next;
            }
        }
        p->next = nullptr;
        p = d->next;
        delete d;
        return p;
    }

    ListNode * deleteDuplicates2(ListNode * head) {
        ListNode *d = new ListNode(-1), *a = head, *b, *p;
        p = d;
        while(a) {
            b = a->next;
            if(b && a->val == b->val) {
                while(b && a->val == b->val)
                    b = b->next;
                a = b;
            } else {
                p = p->next = a;
                a = a->next;
            }
        }
        p->next = nullptr;
        return d->next;
    }

};