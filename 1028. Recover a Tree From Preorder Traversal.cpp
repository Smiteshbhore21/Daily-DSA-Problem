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
    int index = 0;
    int n = 0;
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        return recur(traversal, 0);
    }

    TreeNode* recur(string& traversal, int depth) {
        if (index >= n)
            return NULL;
        int count = 0;
        int tempI = index;
        while (tempI < n && !isdigit(traversal[tempI])) {
            count++;
            tempI++;
        }
        if (count != depth)
            return NULL;
        index = tempI;
        int val = 0;
        while (index < n && isdigit(traversal[index])) {
            val = val * 10 + (traversal[index] - '0');
            index++;
        }
        TreeNode* node = new TreeNode(val);
        node->left =  recur(traversal, depth+1);
        node->right =  recur(traversal, depth+1);
        return node;
    }
};
