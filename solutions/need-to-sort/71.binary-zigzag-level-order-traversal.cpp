#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include <queue>
#include "tree.h"
#include "linklist.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
		if (!root) return {};
		vector<vector<int>> t;
		deque<int> d;
		queue<TreeNode*> q;
		TreeNode *r = root, *p;
		q.push(root);
		bool f = true;
		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (f)
				d.push_front(p->val);
			else
				d.push_back(p->val);
			if(p->left) 
			    q.push(p->left);
	        if(p->right)
	            q.push(p->right);
			if (p == r) {
				if (!q.empty())
					r = q.back();
				t.push_back(vector<int>(d.rbegin(), d.rend()));
				d.clear();
				f = !f;
			}
		}
		return t;
	}
};