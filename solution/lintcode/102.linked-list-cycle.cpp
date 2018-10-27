#include "Link_list.h"

class Solution {
public:
    bool hasCycle(ListNode * head) {
        ListNode *p = head, *q;
        if(p) {
            q = p->next;
            while(q && q->next) {
                if(p == q) 
                    return true;
                p = p->next;
                q = q->next->next;
            }
        }
        return false; 
    }
};