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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (abs(leftH - rightH) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }
};
