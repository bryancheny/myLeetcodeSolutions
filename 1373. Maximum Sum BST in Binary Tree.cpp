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
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum < 0 ? 0 : maxsum;
    }
    vector<int> dfs(TreeNode* root) {
        // Returns sum of subtree, negative if subtree is not a binary search tree
        // 2nd and 3rd values are the min and max of the tree
        if (!root) return {};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        if ((!left.empty() && left.size() == 1) || (!right.empty() && right.size() == 1)) return {0};
        if ((!left.empty() && left[2] >= root->val) || (!right.empty() && right[1] <= root->val)) return {0};
        vector<int> curr(3,root->val); 
        if (!left.empty()) {
            curr[0] += left[0];
            curr[1] = left[1];
        }
        if (!right.empty())  {
            curr[0] += right[0];
            curr[2] = right[2];
        }
        maxsum = max(curr[0],maxsum);
        return curr;
        
    }
    int maxsum = INT_MIN;
};
