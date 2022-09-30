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
    long pathSum(TreeNode* root, long targetSum, bool connected = false) {
        if (!root) return 0;
        if (!connected) {
            if (root->val == targetSum) {
                return 1 + pathSum(root->left, 0, true) + pathSum(root->left, targetSum, false) + pathSum(root->right, 0, true) + pathSum(root->right, targetSum, false);
            }
            else {
                return pathSum(root->left, targetSum - root->val, true) + pathSum(root->left, targetSum, false) + pathSum(root->right, targetSum - root->val, true) + pathSum(root->right, targetSum, false);
            }
        }
        else {
            if (root->val == targetSum) {
                return 1 + pathSum(root->left, 0, true) + pathSum(root->right, 0, true);
            }
            else {
                return pathSum(root->left, targetSum - root->val, true) + pathSum(root->right, targetSum - root->val, true);
            }
        }
    }
};
