#include "linklist.h"
#include <set>

using namespace std;

class Solution {
public:
    ListNode * detectCycle(ListNode * head) {
        ListNode *p = head, *q;
        if(p) {
            q = p->next;
            while(q && q->next) {
                if(p == q) {
                    int c = 1;
                    for(p = p->next; p != q; ++c)
                        p = p->next;
                    p = q = head;
                    while(c > 0) {
                        p = p->next;
                        --c;
                    }
                    while(p != q) {
                        p = p->next;
                        q = q->next;
                    }
                    return p;  
                } 
                p = p->next;
                q = q->next->next;
            }
        }
        return nullptr;
    }

    ListNode * detectCycle(ListNode * head) {
        set<ListNode*> s;
        ListNode *p = head;
        while(p) {
            if(s.find(p) != s.end())
                return p;
            s.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};