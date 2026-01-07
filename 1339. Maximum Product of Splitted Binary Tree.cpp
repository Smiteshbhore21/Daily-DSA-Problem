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
int MOD = 1e9 + 7;
class Solution {
public:
    // unordered_map<int, long long> atNodeSum;
    vector<int> atNodeSum;
    int maxProduct(TreeNode* root) {
        long long sum = 0;
        sum = dfs(root, 0);
        long long result = 0;
        for (auto& y : atNodeSum) {
            long long tree1 = y;
            long long tree2 = sum - y;
            result = max(tree1 * tree2, result);
            // cout << x << '-' << y << " ";
        }
        return result % MOD;
    }

    long long dfs(TreeNode* node, int sum) {
        if (node == NULL)
            return 0;
        sum += (node->val);
        long long left = dfs(node->left, 0);
        long long right = dfs(node->right, 0);
        sum += (left + right);
        // atNodeSum[node->val] = sum;
        atNodeSum.push_back(sum);
        return sum;
    }
};
