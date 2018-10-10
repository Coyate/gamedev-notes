#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <unordered_set>
#include <set>
#include <Windows.h>
using namespace std;

#include "tree.h"

class Solution {
public:
	int maxDepth(TreeNode * root) {
		if (!root)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode *p = root;
		int d = 0;
		while (!q.empty()) {
			TreeNode *t = q.front();
			q.pop();
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
			if (t == p) {
				++d;
				p = q.empty() ? nullptr : q.back();
			}
		}
		return d;
	}

    int maxDepth2(TreeNode * root) {
		return depth(root, 0);
	}
	int depth(TreeNode *p, int d) {
		return p ? max(depth(p->left, d + 1), depth(p->right, d + 1)) : d;
	}
};

int main() {
	BinaryTree bt({ 1,2,3,4,5,6,7});

	Solution solu;
	cout << solu.maxDepth(bt.head) << endl;

	system("PAUSE");
	return 0;
}
