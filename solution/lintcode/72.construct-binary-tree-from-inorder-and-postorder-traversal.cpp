#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	TreeNode *RecursiveBuild(const vector<int> &inorder, const vector<int> &postorder, size_t inL, size_t inR, size_t postL, size_t postR) {
		if (inL > inR || postL > postR || inR - inL != postR - postL ||
			inL > inorder.size() || inR > inorder.size() || postL > postorder.size() || postR > postorder.size()) {
			return nullptr;
		}
		TreeNode *root = new TreeNode(postorder[postR]);
		auto pivot = find(inorder.begin() + inL, inorder.begin() + inR, postorder[postR]) - inorder.begin();
		root->left = RecursiveBuild(inorder, postorder, inL, pivot - 1, postL, postL + pivot - inL - 1);
		root->right = RecursiveBuild(inorder, postorder, pivot + 1, inR, postR + pivot - inR, postR - 1);
		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		TreeNode* head = nullptr;
		if (!inorder.empty() && !postorder.empty() && inorder.size() == postorder.size()) {
			head = RecursiveBuild(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
		}
		return head;
	}

};

int main() {
	vector<vector<int>> vvin{
		{},
		{1,2,3},
		{3,2,5,4,1,6,8,7,9}
	};
	vector<vector<int>> vvpost{
		{},
		{1,3,2},
		{3,5,4,2,8,9,7,6,1}
	};
	Solution solu;
	TreeNode * head0 = solu.buildTree(vvin[0], vvpost[0]);
	TreeNode * head1 = solu.buildTree(vvin[1], vvpost[1]);
	TreeNode * head2 = solu.buildTree(vvin[2], vvpost[2]);
	return 0;
}