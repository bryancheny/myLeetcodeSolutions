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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* lastodd = head;
        ListNode* firsteven = head->next;
        ListNode* lasteven = head->next;
        ListNode* curr = head->next->next;
        bool parity = 1;
        while (curr) {
            if (parity) { // odd 
                lastodd->next = curr;
                lastodd = curr;
            }
            else {
                lasteven->next = curr;
                lasteven = curr;
            }
            parity ^= 1;
            curr = curr->next;
        }
        lastodd->next = firsteven;
        lasteven->next = nullptr;
        return head;
    }
};
