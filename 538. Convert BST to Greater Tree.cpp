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
    TreeNode* convertBST(TreeNode* root) {
        // Right root left, inorder transversal except going right instead of left
        int presum = 0;
        dfs(root,presum);
        return root;
    }
    void dfs(TreeNode* root, int &presum) {
        if (!root) return;
        dfs(root->right, presum);
        presum += root->val;
        root->val = presum;
        dfs(root->left, presum);
        return;
    }
    
    
};
