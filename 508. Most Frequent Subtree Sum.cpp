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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        int max = 0;
        for (auto it:count) {
            if (it.second > max) {
                max = it.second;
            }
        }
        for (auto it:count) {
            if (it.second == max) {
                res.push_back(it.first);
            }
        }
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int curr = dfs(root->left) + dfs(root->right) + root->val;
        count[curr]++;
        return curr;
    }
    unordered_map<int,int> count;
};
