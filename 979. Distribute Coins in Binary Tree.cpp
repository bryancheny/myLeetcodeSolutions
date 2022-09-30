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
    int distributeCoins(TreeNode* root) { // how many moves it takes to fill all and move excess to top, or move from top to bottom if not enough
        return helper(root).first;
        
    }
    pair <int,int> helper(TreeNode* root) { // First value is how many moves it takes to fill all and move excess to top, or move to bottom
        // Second value is how much in excess, negative if scarce
        if (!root) return {0,0};
        pair<int,int> l = helper(root->left);
        pair<int,int> r = helper(root->right);
        int excess = l.second + r.second + root->val - 1;
        return {l.first+r.first+abs(excess), excess};  
    }
};
