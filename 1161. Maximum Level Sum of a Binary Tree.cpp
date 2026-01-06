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
    unordered_map<int, int> sumAtLevel;
    int maxLevelSum(TreeNode* root) {
        traverse(root, 1);
        int result = 0;
        int maxVal = INT_MIN;
        for (auto& [key, val] : sumAtLevel) {
            if (maxVal < val) {
                maxVal = val;
                result = key;
            } else if (maxVal == val) {
                result = min(key, result);
            }
        }
        return result;
    }

    void traverse(TreeNode* node, int level) {
        if (node == nullptr)
            return;
        sumAtLevel[level] += node->val;
        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
        return;
    }
};
