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
class Solution {
public:
    static bool compare(ListNode* &a, ListNode* &b) {
        return a->val < b->val;
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        vector<ListNode*> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }
        sort(v.begin(),v.end(),compare);
        for (int i = 0; i < v.size() - 1; i++) {
            v[i]->next = v[i+1];
        }
        v.back()->next = nullptr;
        return v[0];
    }
};
