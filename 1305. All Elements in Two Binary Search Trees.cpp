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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if (root1) {
            while (root1->left) {
            s1.push(root1);
            root1 = root1->left;
            }
            s1.push(root1);   
        }
        if (root2) {
            while (root2->left) {
            s2.push(root2);
            root2 = root2->left;
            }
            s2.push(root2);
        }
        
        while (!s1.empty() || !s2.empty()) {
            if (s1.empty() || (!s2.empty() && s1.top()->val > s2.top()->val)) {
                TreeNode* curr = s2.top();
                s2.pop();
                res.push_back(curr->val);
                if (curr->right) {
                    curr = curr->right;
                    while (curr->left) {
                        s2.push(curr);
                        curr = curr->left;
                    }
                    s2.push(curr);
                }
            }
            else {
                TreeNode* curr = s1.top();
                s1.pop();
                res.push_back(curr->val);
                if (curr->right) {
                    curr = curr->right;
                    while (curr->left) {
                        s1.push(curr);
                        curr = curr->left;
                    }
                    s1.push(curr);
                }
            }
        }
        return res;
    }
};
