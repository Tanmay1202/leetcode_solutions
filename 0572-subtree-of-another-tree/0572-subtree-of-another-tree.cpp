/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool isIdentical(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;

        return l->val == r->val &&
               isIdentical(l->left, r->left) &&
               isIdentical(l->right, r->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;

        if (isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};