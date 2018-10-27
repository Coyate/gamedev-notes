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
	/**
	* @param root: A Tree
	* @return: Postorder in ArrayList which contains node values.
	*/
	vector<int> postorderTraversal(TreeNode * root) {
		if (!root)
			return {};
		TreeNode *p = root;
		TreeNode *r = nullptr;
		vector<TreeNode*> s;
		vector<int> result;
		while (p || !s.empty()) {
			while (p) {
				s.push_back(p);
				p = p->left;
			}
			p = s.back();
			if (!p->right || p->right == r) {
				result.push_back(p->val);
				s.pop_back();
				r = p;
				p = nullptr;
			}
			else {
				p = p->right;
			}
		}
		return result;
	}
};

int main() {


	BinaryTree bt1({ 1 }, { 1 });
	BinaryTree bt2({ 0,1,9,2,5,7,4,3,6 }, { 9,1,5,2,7,0,3,4,6 });
	BinaryTree bt3({ 10 }, { 10 });

	Solution solu;


	auto path = solu.postorderTraversal(bt2.head);

	for (auto node : path) {
		cout << node << " -> ";
	}
	cout << endl;


	system("PAUSE");
	return 0;
}
