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
    int maxPathSum(TreeNode* root) {
        return dfs(root).first;
    }
    pair<int,int> dfs(TreeNode* root) { // First value is the max optimal path, Second value is the max optimal path starting from root to any node
        if (!root->left && !root->right) return {root->val, root->val};
        else if (!root->left) {
            pair<int,int> right = dfs(root->right);
            return {max(max(right.first, right.second + root->val), root->val), max(root->val, root->val + right.second)};
        }
        else if (!root->right) {
            pair<int,int> left = dfs(root->left);
            return {max(max(left.first, left.second + root->val), root->val), max(root->val, root->val + left.second)};
        }
        else {
            pair<int,int> left = dfs(root->left);
            pair<int,int> right = dfs(root->right);
            int maximum = max(left.first, right.first);
            maximum = max(maximum, root->val);
            maximum = max(maximum, root->val + left.second);
            maximum = max(maximum, root->val + right.second);
            maximum = max(maximum, root->val + left.second + right.second);
            int heightmax = max(root->val, root->val + left.second);
            heightmax = max(heightmax, root->val + right.second);
            return {maximum, heightmax};
        }
    }
};
