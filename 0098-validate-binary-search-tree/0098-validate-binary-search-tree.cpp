class Solution {
private:
    TreeNode* prev = nullptr;

    bool inorder(TreeNode* root) {
        if (!root) return true;

        
        if (!inorder(root->left)) return false;

        
        if (prev && root->val <= prev->val)
            return false;

        prev = root;

        return inorder(root->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
