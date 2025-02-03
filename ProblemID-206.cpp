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
    ListNode* reverseList(ListNode* head)
    {
    if (!head || !head->next) return head; 

        ListNode* newHead = reverseList(head->next); // Reverse the rest of the list
        head->next->next = head; // Make the next node point to the current node
        head->next = nullptr; // Set current node's next to NULL

        return newHead; // Return new head of reversed list
    }
};