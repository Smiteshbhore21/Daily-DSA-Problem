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
    unordered_map<int, int> mp;
    int n = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        n = preorder.size();
        for (int i = 0; i < n; i++)
            mp[postorder[i]] = i;
        return recur(0, n - 1, 0, n - 1, preorder, postorder);
    }
    TreeNode* recur(int i1, int i2, int j1, int j2, vector<int>& preorder,
                    vector<int>& postorder) {
        if (i1 > i2 || j1 > j2)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i1]);
        if (i1 == i2)
            return root;
        int r = mp[preorder[i1 + 1]];
        int size = r - j1 + 1;
        root->left = recur(i1 + 1, i1 + size, j1, r, preorder, postorder);
        root->right =
            recur(i1 + size + 1, i2, r + 1, j2 - 1, preorder, postorder);
        return root;
    }
};
