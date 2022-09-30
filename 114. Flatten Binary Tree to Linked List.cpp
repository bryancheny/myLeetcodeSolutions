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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* last;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if (curr != root) last->right = curr;
            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
            curr->left = nullptr;
            last = curr;
        }
        last->right = nullptr;
    }
};
