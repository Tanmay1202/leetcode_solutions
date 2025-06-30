class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // Create a dummy node before head to simplify edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n+1 steps ahead so slow ends up right before the node to delete
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from end
        slow->next = slow->next->next;

        // Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;  // avoid memory leak
        return newHead;
    }
};
