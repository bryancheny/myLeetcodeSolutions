class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Recursive solution, so we can assume the list has k or less nodes
        ListNode* jumpk = head;
        for (int i = 0; i < k; i++) {
            if (!jumpk) return head;
            jumpk = jumpk->next;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != jumpk) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }
        head->next = reverseKGroup(jumpk, k);
        return prev;
    }
};
