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
	/*
	 * @param root: the root of binary tree
	 * @param target: An integer
	 * @return: all valid paths, a valid path is form root node to any leaf node
	 */
    // Recur solution
	vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
		if (!root)
			return {};
		vector<vector<int>> result;
		findPath(root, target, 0, {}, result);
		return result;
	}

	void findPath(TreeNode *root, int target, int num, vector<int> vi, vector<vector<int>> &result) {
		if (!root)
			return;
		else {
			vi.push_back(root->val);
			if ((num + root->val) == target) {
				if (!root->left && !root->right)
					result.push_back(vi);
			}
			if (root->left)
				findPath(root->left, target, num + root->val, vi, result);
			if (root->right)
				findPath(root->right, target, num + root->val, vi, result);
		}
	}

	// non-Recur Solution
	vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
		if (!root)
			return{};
		vector<vector<int>> result;
		vector<TreeNode*> s;
		TreeNode *p = root;
		TreeNode *n = nullptr;
		while (p || !s.empty()) {
			while (p) {
				s.push_back(p);
				p = p->left;
			}
			p = s.back();

			if (!p->right || n == p->right) {
				// visit p
				if (!p->left && !p->right) {
					vector<int> vi;
					for (auto &p : s) {
						vi.push_back(p->val);
					}
					if(accumulate(vi.begin(), vi.end(), 0) ==  target)
						result.push_back(vi);
				}
				n = p;
				p = nullptr;
				s.pop_back();
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


	auto paths = solu.binaryTreePathSum(bt2.head, 10);
	for (auto &path : paths) {
		for (auto node : path) {
			cout << node << " -> ";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}
