class Solution {
    int result = 0;

    public int averageOfSubtree(TreeNode root) {
        solve(root);
        return result;
    }

    public int[] solve(TreeNode node) {
        if (node == null) {
            return new int[]{0, 0};
        }

        int[] left = solve(node.left);
        int[] right = solve(node.right);

        int sum = left[0] + right[0] + node.val;
        int count = left[1] + right[1] + 1;

        if (node.val == sum / count) {
            result++;
        }

        return new int[]{sum, count};
    }
}
