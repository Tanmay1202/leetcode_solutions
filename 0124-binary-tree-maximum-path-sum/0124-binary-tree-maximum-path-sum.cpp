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
    int ans = INT_MIN;
    int dfs(TreeNode* root)
    {
        if(!root)
        return 0;

        int L = dfs(root->left);
        int R = dfs(root->right);

        L = max(0, L);
        R = max(0, R);

        ans = max(ans, L + root->val + R);

        return root->val + max(L, R);
    }
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return ans;
    }
};