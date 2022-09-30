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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root) dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int num, int &res) {
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            res += num;
        }
        if (root->left) dfs(root->left, num, res);
        if (root->right) dfs(root->right, num, res);
        return;
    }
};
