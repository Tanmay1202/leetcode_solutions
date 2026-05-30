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
    int countLeft(TreeNode* root)
    {
        if(!root) return 0;

        return 1 + countLeft(root->left);
    }

    int countRight(TreeNode* root)
    {
        if(!root) return 0;

        return 1 + countRight(root->right);
    }

    int countNodes(TreeNode* root)
    {
        if(!root) return 0;

        int left = 1 + countLeft(root->left);
        int right = 1 + countRight(root->right);

        if(left == right)
        {
            return pow(2, left) - 1;
        }


        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};