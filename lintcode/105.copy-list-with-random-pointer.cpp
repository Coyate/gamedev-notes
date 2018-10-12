// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};


class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
        	if (!head)
    			return nullptr;
    		RandomListNode *p = head;
    		while (p) {
    			RandomListNode *node = new RandomListNode(p->label);
    			node->next = p->next;
    			p->next = node;
    			p = node->next;
    		}
    		p = head;
    		RandomListNode *l = p->next;
    		while (p) {
    			if(p->random)
    				l->random = p->random->next;
    			p = l->next;
    			l = p ? p->next : nullptr;
    		}
    		p = head;
    		l = p->next;
    		head = l;
    		while (p) {
    			p->next = l->next;
    			p = p->next;
    			if (p) {
    				l->next = p->next;
    				l = l->next;
    			}
    		}
    		return head;
        }
    };