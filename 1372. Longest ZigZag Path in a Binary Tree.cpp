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
    int longestZigZag(TreeNode* root) {
        int res = 0; 
        dfs(root,res,-1,0);
        return res;
    }
    void dfs(TreeNode* root, int &res, int currlength, bool dir) { // if go left, pass false, if go right pass true
        if (!root) {
            res = max(res, currlength);
            return;
        }
        if (dir) { // root is Right child
            dfs(root->left, res, currlength + 1, 0);
            dfs(root->right, res, 0, 1);
        }
        else { // root is left child
            dfs(root->left, res, 0, 0);
            dfs(root->right, res, currlength + 1, 1);
        }
    }
     
};
