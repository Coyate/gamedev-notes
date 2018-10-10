
//  Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class Solution {
public:
    void deleteNode(ListNode * node) {
        if(node && node->next) {
            ListNode* p = node->next;
            node->val = p->val;
            node->next = p->next;
            delete p;
        }
    }
};