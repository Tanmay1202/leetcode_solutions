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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next)
        return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr)
        {
            bool isDuplicate = false;

            while(curr->next && curr->val == curr->next->val)
            {
                isDuplicate = true;
                curr = curr->next;
            }

            if(isDuplicate)
            prev->next = curr->next;
            else
            prev = prev->next;

            curr = curr->next;
        }

        return dummy->next;
    }
};