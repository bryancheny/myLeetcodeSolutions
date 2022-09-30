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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root);
        TreeNode* curr = root;
        while (true) {
            if (curr->left && !curr->right) {
                curr = curr->left;
            }
            if (!curr->left && curr->right) {
                curr = curr->right;
            }
            if (!curr->left && !curr->right) {
                return curr;
            }
            else {
                if (dp[curr->left] == dp[curr->right]) return curr;
                else if (dp[curr->left] < dp[curr->right]) curr = curr->right;
                else curr = curr->left;
            }
        }
        return curr;
    }
    int depth(TreeNode* root) {
        if (!root) return 0;
        int d = max(depth(root->left),depth(root->right));
        dp[root] = d + 1;
        return d + 1;
    }
private:
    unordered_map<TreeNode*, int> dp; // Records the depth of each node
};
