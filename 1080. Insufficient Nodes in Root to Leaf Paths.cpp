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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) return nullptr;
        if (dfs(root, limit, 0) < limit) return nullptr;
        return root;
    }
    int dfs(TreeNode* root, int limit, int presum) { // Return max path sum of node
        if (root->left && root->right) {
            int l = dfs(root->left, limit, presum + root->val);
            int r = dfs(root->right, limit, presum + root->val);
            presum = max(l,r);
            if (l < limit) root->left = nullptr;
            if (r < limit) root->right = nullptr;
        }
        else if (root->right) {
            int r = dfs(root->right, limit, presum + root->val);
            if (r < limit) root->right = nullptr;
            presum = r;
        }
        else if (root->left) {
            int l = dfs(root->left, limit, presum + root->val);
            if (l < limit) root->left = nullptr;
            presum = l;
        }
        else {
            presum = presum + root->val;
        }
        return presum;
    }
};
