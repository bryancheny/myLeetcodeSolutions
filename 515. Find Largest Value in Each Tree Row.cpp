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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (root) q.push(root);
        while(!q.empty()) {
            int levelsize = q.size();
            int levelmax = INT_MIN;
            for (int i = 0; i < levelsize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                levelmax = max(levelmax, curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(levelmax);
        }
        return res;
    }
};
