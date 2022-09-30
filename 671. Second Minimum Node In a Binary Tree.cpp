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
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);;
    }
    int dfs(TreeNode* root, int minimum) {
        if (!root) return -1;
        if (root->val > minimum) return root->val;
        int l = dfs(root->left, minimum);
        int r = dfs(root->right, minimum);
        if (l != -1 && r == -1) return l;
        if (l == -1 && r != -1) return r;
        else return min(r,l);
    }
};
