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
    void helper(TreeNode* root, vector<int> &ans)
    {
        if(!root)
        return;

        if(root->left == NULL && root->right == NULL)
        ans.push_back(root->val);

        helper(root->left, ans);
        helper(root->right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1 && !root2)
        return true;

        vector<int> l1;
        vector<int> l2;

        helper(root1, l1);
        helper(root2, l2);

        if(l1 == l2)
        return true;

        return false;


    }
};