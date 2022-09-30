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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return helper(root)[0];        
    }
    vector<int> helper(TreeNode* root) { // {difference, minimum, maximum} as output
        vector<int> l,r;
        vector<int> res = {0,root->val,root->val};
        if (root->left) {
            l = helper(root->left);
            res[0] = max(res[0],l[0]);
            res[1] = min(res[1],l[1]);
            res[2] = max(res[2],l[2]);
        }
        if (root->right) {
            r = helper(root->right);
            res[0] = max(res[0],r[0]);
            res[1] = min(res[1],r[1]);
            res[2] = max(res[2],r[2]);
        }
        res[0] = max(res[0],abs(root->val - res[1]));
        res[0] = max(res[0],abs(root->val - res[2]));
        return res;
        
    }
};
