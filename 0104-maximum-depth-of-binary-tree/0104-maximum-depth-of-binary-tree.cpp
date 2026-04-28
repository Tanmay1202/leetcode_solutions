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
    void traversal(TreeNode* root, int &ans, int count)
    {
        if(!root)
        {
            ans = max(ans, count);
            return;
        }

        traversal(root->left, ans, count+1);
        traversal(root->right, ans, count+1);
    }

    int maxDepth(TreeNode* root) {
        int ans = 0;

        if(!root) return 0;

        traversal(root, ans, 0);

        return ans;
    }
};