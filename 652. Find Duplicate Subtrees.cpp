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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,pair<int,int>> hash;
        vector<TreeNode*> res;
        dfs(root,hash,res);
        return res;
    }
    int dfs(TreeNode* root, unordered_map<string,pair<int,int>> &hash, vector<TreeNode*> &res) {
        if (!root) return 0;
        string s = to_string(root->val) + "," + to_string(dfs(root->left, hash, res)) + "," + to_string(dfs(root->right, hash, res));
        if (hash.find(s) == hash.end()) {
            hash[s] = {nextID,1};
            nextID++;
        }
        else if (++hash[s].second == 2) {
            res.push_back(root);
        }
        return hash[s].first;
    }
private:
    int nextID = 1;
};
