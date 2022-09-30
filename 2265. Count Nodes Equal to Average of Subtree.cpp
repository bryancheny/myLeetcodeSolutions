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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    pair<int,int> dfs(TreeNode* root, int &res) { // Sum + number of nodes
        if (!root) return {0,0};
        pair<int,int> l = dfs(root->left, res);
        pair<int,int> r = dfs(root->right, res);
        if ((l.first + r.first + root->val) / (l.second + r.second + 1) == root->val) res ++;
        return {l.first + r.first + root->val, l.second + r.second + 1};
    }
    
};
