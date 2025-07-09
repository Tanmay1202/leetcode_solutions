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
private:
    void helper(TreeNode* root, int &ans, int h)
    {
        if(!root)
        return;

        h += 1;

        if(!root->left && !root->right)
        {
            ans = max(h, ans);
            return;
        }

        helper(root->left, ans, h);
        helper(root->right, ans, h);
    }
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root)
        return 0;

        if(!root->left && !root->right)
        return 1;

        int ans = 0;

        helper(root, ans, 0);

        return ans;
    }
};