/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string res; 
        TreeNode* curr;
        q.push(root);
        while (!q.empty()) {
            res.push_back(',');
            curr = q.front();
            q.pop();
            if (!curr) {
                res += "n";
            } 
            else {
                res += to_string(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') values.push_back("");
            else {values.back().push_back(data[i]);}
        }
        if (values[0] == "n") return nullptr;
        TreeNode* head = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(head);
        for (int i = 1; i < values.size(); i+=2) {
            TreeNode* curr = q.front();
            q.pop();
            if (values[i] != "n") {
                TreeNode* l = new TreeNode(stoi(values[i]));
                curr->left = l;
                q.push(l);
            }
            if (values[i+1] != "n") {
                TreeNode* r = new TreeNode(stoi(values[i+1]));
                curr->right = r;
                q.push(r);
            }
        }
        return head;
    }
};
