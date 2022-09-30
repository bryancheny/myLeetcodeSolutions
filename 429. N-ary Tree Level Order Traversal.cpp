/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            res.push_back({});
            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();
                res.back().push_back(curr->val);
                for (auto &j : curr->children) {
                    q.push(j);
                }
            }
        }
        return res;
    }
};
