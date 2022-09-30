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
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (dp.find(root) != dp.end()) return dp[root];
        int ans;
        if (root->left && root->right) {
            ans = max(rob(root->left) + rob(root->right), rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right) + root->val);
        }
        else if (!root->left && !root->right) {
            ans = root->val;
        }
        else if (root->left && !root->right) {
            ans = max(rob(root->left), rob(root->left->left) + rob(root->left->right) + root->val);
        }
        else {
            ans = max(rob(root->right),rob(root->right->left) + rob(root->right->right) + root->val);
        }
        dp[root] = ans;
        return ans;
    }
private:
    unordered_map<TreeNode*, int> dp;
};
