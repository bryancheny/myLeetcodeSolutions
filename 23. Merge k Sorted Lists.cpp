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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // sort the array of first elements first, remove smallest element and add its successor - multiset or set with custom comparator
        multiset<int> mset;
        unordered_map<int,vector<ListNode*>> hash;
        for (auto i:lists) {
            if (!i) continue;
            mset.insert(i->val);
            hash[i->val].push_back(i);
        }
        if (hash.empty()) return nullptr;
        ListNode* head = hash[*mset.begin()].back();
        ListNode* curr = head;
        ListNode* nex;
        hash[*mset.begin()].pop_back();
        mset.erase(mset.begin());
        if (head->next) {
            mset.insert(head->next->val);
            hash[head->next->val].push_back(head->next);
        }
        
        while (!mset.empty()) {
            nex = hash[*mset.begin()].back();
            curr->next = nex;
            curr = nex;
            // Remove smallest element
            hash[*mset.begin()].pop_back();
            mset.erase(mset.begin());
            // Add the successor of smallest element
            if (curr->next) {
                mset.insert(curr->next->val);
                hash[curr->next->val].push_back(curr->next);
            }
        }
        return head;
    }
