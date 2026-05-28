class Solution {
    int maxDiameter = 0;

    public int checker(TreeNode root) {
        if (root == null) return 0;
        
        int left = checker(root.left);
        int right = checker(root.right);
        
        // Update the global max with the path through the current node
        maxDiameter = Math.max(maxDiameter, left + right);
        
        // Return the height of the current node
        return 1 + Math.max(left, right);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        maxDiameter = 0; // <--- RESET HERE
        checker(root);
        return maxDiameter;
    }
}
