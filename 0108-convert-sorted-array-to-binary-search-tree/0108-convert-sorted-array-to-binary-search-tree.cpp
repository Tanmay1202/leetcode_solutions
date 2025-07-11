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
    TreeNode* construct(vector<int>& nums, int l, int r)
    {
        if(l>r)
        return nullptr;

        int m = l + (r - l)/2;

        TreeNode* root = new TreeNode(nums[m]);

        root->left = construct(nums, l, m-1);
        root->right = construct(nums, m+1, r);

        return root;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        return construct(nums, 0, n-1);
    }
};