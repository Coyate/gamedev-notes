// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#pragma once

#include <iostream>
#include <vector>
using std::ostream;
using std::vector;

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */

	TreeNode* RecursiveBuild(const vector<int> &preorder, const vector<int> &inorder, size_t preL, size_t preR, size_t inL, size_t inR) {
		if ((preL > preR) || (inL > inR) || (preR - preL) != (inR - inL)) {
			return nullptr;
		}
		else {
			TreeNode* root = new TreeNode(preorder[preL]);
			auto iter = find(inorder.cbegin(), inorder.cend(), preorder[preL]);
			auto pos = iter - inorder.cbegin();
			root->left = RecursiveBuild(preorder, inorder, preL + 1, preL + pos - inL, inL, pos - 1);
			root->right = RecursiveBuild(preorder, inorder, preL + pos - inL + 1, preR, pos + 1, inR);
			return root;
		}
	}

    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {

		TreeNode* head = nullptr;
		if (!preorder.empty() && !inorder.empty() && preorder.size() == inorder.size()) {
			head = RecursiveBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
		}
		return head;
    }
};

