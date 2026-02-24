/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int result = 0;

    public int sumRootToLeaf(TreeNode root) {
        dfs(root, 0);
        return result;
    }

    public void dfs(TreeNode node, int num) {
        if (node == null) {
            return;
        }
        num = (num << 1) | node.val;

        if (node.left == null && node.right == null) {
            result += num;
            return;
        }
        dfs(node.left, num);
        dfs(node.right, num);
    }
}
