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
    public HashMap<TreeNode, Integer> depthMap = new HashMap<>();
    public int maxDepth = -1;

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        dfs(root, 0);

        return LCA(root);
    }

    private void dfs(TreeNode node, int level) {
        if (node == null)
            return;

        maxDepth = Math.max(level, maxDepth);
        depthMap.put(node, level);

        dfs(node.left, level + 1);
        dfs(node.right, level + 1);
    }

    private TreeNode LCA(TreeNode node) {

        if (node == null)
            return null;

        if (depthMap.get(node) == maxDepth) {
            return node;
        }

        TreeNode left = LCA(node.left);
        TreeNode right = LCA(node.right);

        if (left != null && right != null)
            return node;
        if (left != null)
            return left;
        if (right != null)
            return right;
        return null;
    }
}
