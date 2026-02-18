/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<pair<int, int>, vector<int>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto front = q.front();

            TreeNode* node = front.first;
            int x = front.second.first;
            int y = front.second.second;

            q.pop();

            mp[{y, x}].push_back(node->val);

            if (node->left) {
                q.push({node->left, {x + 1, y - 1}});
            }

            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        int prevCol = INT_MIN;

        for (auto& it : mp) {
            int col = it.first.first;

            sort(it.second.begin(), it.second.end());

            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }

            res.back().insert(res.back().end(), it.second.begin(),
                              it.second.end());
        }

        return res;
    }
};