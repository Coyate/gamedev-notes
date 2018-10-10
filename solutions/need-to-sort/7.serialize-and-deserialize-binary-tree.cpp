#include "tree.h"
#include <string>

class Solution {
public:
	string serialize(TreeNode * root) {
		if (!root) return "#";
		return (char)(root->val + '0') + serialize(root->left) + serialize(root->right);
	}

	TreeNode * deserialize(string &data) {
		if (data.empty())
			return nullptr;
		if (data[0] == '#') {
			data.erase(data.begin());
			return nullptr;
		}
		TreeNode *p = new TreeNode(data[0] - '0');
		data.erase(data.begin());
		p->left = deserialize(data);
		p->right = deserialize(data);
		return p;
	}
};