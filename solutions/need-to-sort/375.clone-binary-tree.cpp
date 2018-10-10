#include "tree.h"

class Solution {
public:
    TreeNode * cloneTree(TreeNode * root) {
		if(!root)
			return nullptr;
		TreeNode *node = new TreeNode(root->val);
		if(root->left)
			node->left = cloneTree(root->left);
		if(root->right)
			node->right = cloneTree(root->right);
		return node;
    }

    TreeNode * cloneTree(TreeNode * root) {
        return root;
    }
};