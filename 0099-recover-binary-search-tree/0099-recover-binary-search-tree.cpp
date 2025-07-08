class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root)
    {
        if (!root) return;

        inorder(root->left);

        // Check for violation of BST property
        if (prev && prev->val > root->val)
        {
            if (!first) first = prev;     // first occurrence
            second = root;                // second occurrence (or update)
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        if (first && second)
            swap(first->val, second->val);  // Only swap values, not pointers
    }
};
