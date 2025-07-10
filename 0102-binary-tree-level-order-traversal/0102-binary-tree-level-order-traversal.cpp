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
    void helper(vector<vector<int>> &ans, vector<int> &temp, TreeNode* root)
    {
        if(!root)
        return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            temp.clear();
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if(curr->left)
                q.push(curr->left);

                if(curr->right)
                q.push(curr->right);
            }

            ans.push_back(temp);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(ans, temp, root);

        return ans;
    }
};