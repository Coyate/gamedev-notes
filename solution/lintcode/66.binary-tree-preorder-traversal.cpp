#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
#include <Windows.h>
using namespace std;

#include "tree.h"

class Solution {
public:
	vector<int> preorderTraversal(TreeNode * root) {
		if (!root)
			return {};
		vector<int> t;
		TreeNode *p = root;
		vector<TreeNode*> s;
		while (p || !s.empty()) {
			while (p) {
				t.push_back(p->val);
				s.push_back(p);
				p = p->left;
			}
			p = s.back();
			s.pop_back();
			p = p->right;
		}
		return t;
	}
};

int main() {
	BinaryTree bt1({ 1 }, { 1 });
	BinaryTree bt2({ 0,1,9,2,5,7,4,3,6 }, { 9,1,5,2,7,0,3,4,6 });
	BinaryTree bt3({ 10 }, { 10 });

	Solution solu;


	auto path = solu.preorderTraversal(bt2.head);

	for (auto node : path) {
		cout << node << " -> ";
	}
	cout << endl;


	system("PAUSE");
	return 0;
}
