/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        if(root == nullptr)
        return;

        if(root->left)
        {
            parent[root->left] = root;
            buildParent(root->left, parent);
        }

        if(root->right)
        {
            parent[root->right] = root;
            buildParent(root->right, parent);
        }
    }

    void restrictDfs(TreeNode* node, int k, int dis, unordered_map<TreeNode*, TreeNode*> parent, unordered_set<TreeNode*> &visited, vector<int> &ans)
    {
        if(node == nullptr || dis == k)
        {
            if(dis == k)
            ans.push_back(node->val);

            return;
        }

        visited.insert(node);

        if(node->left && !visited.count(node->left))
        restrictDfs(node->left, k, dis + 1, parent, visited, ans);

        if(node->right && !visited.count(node->right))
        restrictDfs(node->right, k, dis + 1, parent, visited, ans);

        if(parent[node] && !visited.count(parent[node]))
        restrictDfs(parent[node], k, dis + 1, parent, visited, ans);
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;

        parent[root] = nullptr;

        buildParent(root, parent);

        unordered_set<TreeNode*> visited;

        restrictDfs(target, k, 0, parent, visited, ans);

        return ans;

        



        
    }
};