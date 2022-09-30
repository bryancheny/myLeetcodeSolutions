/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        return vectorToBST(v,0,v.size()-1);
    }
    TreeNode* vectorToBST(vector<int> &v, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* curr = new TreeNode(v[(start + end)/2]);
        curr->left = vectorToBST(v,start,(start + end)/2 - 1);
        curr->right = vectorToBST(v,(start + end)/2 + 1, end);
        return curr;
    }
};
