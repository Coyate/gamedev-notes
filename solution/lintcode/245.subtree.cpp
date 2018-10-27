#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	/**
	* @param T1: The roots of binary tree T1.
	* @param T2: The roots of binary tree T2.
	* @return: True if T2 is a subtree of T1, or false.
	*/
    // recur 552 ms
	bool isSubtree(TreeNode * T1, TreeNode * T2) {
		if (!T2)
			return true;
		if (!T1)
		    return false;
		bool root = false, left = false, right = false;
		if (T1->val == T2->val)
			root = subtreeJudge(T1, T2);
		if (T1->left)
			left = isSubtree(T1->left, T2);
		if (T1->right)
			right = isSubtree(T1->right, T2);
		return root || left || right;
	}

    // nonrecur 476ms

	bool isSubtree2(TreeNode * T1, TreeNode * T2) {
		if (!T2)
			return true;
		if (!T1)
			return false;
		stack<TreeNode*> s;
		TreeNode *p = T1;
		while (p || !s.empty()) {
			while (p) {
				if (p->val == T2->val && subtreeJudge(p, T2))
					return true;
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			p = p->right;
		}
		return false;
	}
	bool subtreeJudge(TreeNode * T1, TreeNode *T2) {
		if (!T1 && !T2)
			return true;
		else if (!T1 || !T2) {
			return false;
		}
		else {
			return (T1->val == T2->val) &&
				subtreeJudge(T1->left, T2->left) &&
				subtreeJudge(T1->right, T2->right);
		}
	}
};