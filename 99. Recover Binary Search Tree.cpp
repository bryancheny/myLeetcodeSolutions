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
    void recoverTree(TreeNode* root) {
       // Inorder transversal 
        stack<TreeNode*> s;
        TreeNode* curr = root;
        vector<TreeNode*> a;
        while(curr ->left) {
                    s.push(curr);
                    curr = curr->left;
                }
        s.push(curr);
        
        while(!s.empty()) {
            curr = s.top();
            s.pop();
            
            a.push_back(curr);
            if(curr->right) {
                curr = curr->right;
                while(curr ->left) {
                    s.push(curr);
                    curr = curr->left;
                }
                s.push(curr);
            }
        }
        TreeNode* fault1 = nullptr;
        TreeNode* fault2 = nullptr;
        for (auto i:a) {
            cout << i->val;
        }
        for(int i = 1; i < a.size(); i++) {
            if (a[i]->val < a[i-1]->val && !fault1) {
                fault1 = a[i-1];
                fault2 = a[i];
            }
            else if(a[i]->val < a[i-1]->val) {
                fault2 = a[i];
            }
        }
        swap(fault1->val,fault2->val);
    }
        
};
