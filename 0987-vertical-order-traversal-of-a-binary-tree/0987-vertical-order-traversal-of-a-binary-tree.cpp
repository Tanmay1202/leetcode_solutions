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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> mpp;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        map<int, vector<pair<int,int>>> pre;;

        mpp[root] = {0, 0};
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front(); q.pop();
            auto [x , y] = mpp[node];
            pre[y].push_back({x, node->val});

            if(node->left)
            {
                mpp[node->left] = {x + 1, y - 1};
                q.push(node->left);
            }
            if(node->right)
            {
                mpp[node->right] = {x + 1, y + 1};
                q.push(node->right);
            }
        }   

        for(auto &it : pre)
        {
            sort(it.second.begin(), it.second.end());
            vector<int> temp;

            for(auto &at: it.second)
            {
                temp.push_back(at.second);
            }

            result.push_back(temp);
        }

        return result;

    }
};