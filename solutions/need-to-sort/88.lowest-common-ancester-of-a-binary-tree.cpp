#include <vector>
#include "tree.h"
using namespace std;

class Solution {
public:
    vector<TreeNode*> path(TreeNode* root, TreeNode* A) {
        vector<TreeNode*> v;
        TreeNode *p = root, *r = nullptr;
        while(p || !v.empty()) {
            while(p) {
                v.push_back(p);
                p = p->left;
            }
            p = v.back();
            if(!p->right || p->right == r) {
                if(p == A)
                    return v;
                v.pop_back();
                r = p;
                p = nullptr;
            } else {
                p = p->right;
            }
        }
    }
    
    TreeNode * lowestCommonAncestor2(TreeNode * root, TreeNode * A, TreeNode * B) {
        vector<TreeNode*> va = path(root, A);
        vector<TreeNode*> vb = path(root, B);
        int a = va.size() - 1, b = vb.size() - 1;
        while(a > b) --a;
        while(b > a) --b;
        while(a >= 0 && b >= 0) {
            if(va[a] == vb[b])
                return va[a];
            --a, --b;
        }
    }

    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(!root || root == A || root == B) 
            return root;
        auto l = lowestCommonAncestor(root->left, A, B);
        auto r = lowestCommonAncestor(root->right, A, B);
        return l && r ? root : l ? l : r? r : nullptr;
    }
};