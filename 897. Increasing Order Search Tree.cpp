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
    TreeNode* increasingBST(TreeNode* root) {
        // Iterate right, root, left 
        stack<TreeNode*> s; 
        TreeNode* curr = root;
        TreeNode* last = nullptr;
        s.push(curr);
        bool FirstNode = true;
        while (!s.empty()) {
            curr = s.top();
            s.pop();
            if (!curr) continue;
            cout << curr->val << " ";
            if (FirstNode || curr == last->left) {
                while(curr->right) {
                s.push(curr);
                curr = curr->right;
                }
            }
            if (curr->left) s.push(curr->left);
            curr->right = last;
            if (!FirstNode) last->left = nullptr;
             last = curr;
            FirstNode = false;
        }
        curr->left = nullptr;
        return curr;
    }
};
