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
    TreeNode* first = NULL;
    void inorder(TreeNode* root, int k, int &count, int &ans)
    {
        if(!root || count >= k)
        return;

        inorder(root->left, k, count, ans);


        count++;
        if(count == k)
        {
            ans =  root->val;
            return;
        }

        

        inorder(root->right, k, count, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int count = 0;
        int ans = -1;
        inorder(root, k , count, ans);

        return ans;
    }
};