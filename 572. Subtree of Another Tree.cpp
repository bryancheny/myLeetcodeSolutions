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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        string subserial = serialize(subRoot);
        bool res = false;
        dfs(root,subserial,res);
        return res;
    }
    string serialize(TreeNode* root) {
        if (!root) return "";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    string dfs(TreeNode* root, string &subserial, bool &res) {
        if (res) return "";
        if (!root) return "";
        string curr = to_string(root->val) + "," + dfs(root->left, subserial, res) + "," + dfs(root->right, subserial, res);
        if (curr == subserial) {
            res = true;
            return "";
        }
        return curr;
    }
};
