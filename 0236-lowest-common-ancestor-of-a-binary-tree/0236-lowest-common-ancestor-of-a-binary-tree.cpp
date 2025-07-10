class Solution {
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = helper(root->left, p, q);
        TreeNode* right = helper(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return helper(root, p, q);
    }
};
