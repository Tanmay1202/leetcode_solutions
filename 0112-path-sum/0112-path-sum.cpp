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
    bool flag = false;
    bool helper(TreeNode* root, int target, int sum)
    {
        if(!root)
        return flag;
        
        sum += root->val;

        if(!root->left && !root->right && sum == target)
        flag = true;

        
        helper(root->left, target, sum);
        helper(root->right, target, sum);

        return flag;
        
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
        return false;

        return helper(root, targetSum, 0);

    }
};