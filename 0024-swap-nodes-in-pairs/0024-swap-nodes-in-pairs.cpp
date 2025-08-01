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
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;
        ListNode* next = NULL;

        while(curr != NULL && curr->next != NULL)
        {
            next = curr->next;

            curr->next = next->next;
            next->next = curr;

            if(prev != NULL)
            {
                prev->next = next;
            }

            prev = curr;
            curr = curr->next;
        }

        return dummy->next;

        
    }
};