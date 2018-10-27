#include <iterator>
#include <Windows.h>
using namespace std;

#include "tree.h"

class DoublyListNode {
public:
	int val;
	DoublyListNode *next, *prev;
	DoublyListNode(int val) {
		this->val = val;
		this->prev = this->next = NULL;
	}
};

class Solution {
public:
    DoublyListNode * bstToDoublyList(TreeNode * root) {
		if (!root)
			return nullptr;
		TreeNode *p = root;
		stack<TreeNode*> s;
		DoublyListNode *dummy = new DoublyListNode(-1);
		DoublyListNode *o = dummy;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();

			DoublyListNode *node = new DoublyListNode(p->val);
			o->next = node;
			node->prev = o;
			o = node;

			p = p->right;
		}
		o = dummy->next;
		delete dummy;
		return o;
    }
};