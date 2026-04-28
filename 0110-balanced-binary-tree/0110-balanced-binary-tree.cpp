/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void height(TreeNode* root, int &ans, int count)
    {
        if(!root)
        {
            ans = max(count, ans);

            return;
        }

        height(root->left, ans, count + 1);
        height(root->right, ans, count + 1);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        return true;

        int hl = 0;
        int hr = 0;

        height(root->left, hl, 0);
        height(root->right, hr, 0);
            
        if (abs(hl - hr) > 1) return false;


        return isBalanced(root->left) && isBalanced(root->right);
    }
};