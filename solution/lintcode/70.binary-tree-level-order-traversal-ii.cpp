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
	vector<vector<int>> levelOrderBottom(TreeNode * root) {
		if (!root)
			return {};
		vector<vector<int>> result;
		TreeNode *p = root;
		TreeNode *r = nullptr;
		vector<TreeNode*> s;
		while (p || !s.empty()) {
			while (p) {
				s.push_back(p);
				p = p->left;
			}
			p = s.back();
			if (!p->right || p->right == r) {
				// visit
				if (s.size() > result.size())
					result.resize(s.size());
				result[s.size() - 1].push_back(p->val);
				// pop
				s.pop_back();
				r = p;
				p = nullptr;
			}
			else {
				p = p->right;
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {


	BinaryTree bt1({ 1 }, { 1 });
	BinaryTree bt2({ 0,1,9,2,5,7,4,3,6 }, { 9,1,5,2,7,0,3,4,6 });
	BinaryTree bt3({ 10 }, { 10 });

	Solution solu;


	auto path = solu.levelOrderBottom(bt2.head);

	for (auto node : path) {
		cout << node << " -> ";
	}
	cout << endl;


	system("PAUSE");
	return 0;
}
