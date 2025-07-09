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
    void helper(TreeNode* root, string temp, string& ans)
    {
        if(!root)
        return;

        temp += (char)root->val + 'a';
        

        if(!root->left && !root->right)
        {
            reverse(temp.begin(), temp.end());
            if(ans.empty())
            {
                ans = temp;
            }
            else if(temp < ans)
            {
                ans = temp;
            }
        }

        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }
public:
    string smallestFromLeaf(TreeNode* root)
    {
        string ans;

        helper(root, "", ans);

        return ans;

    }
};