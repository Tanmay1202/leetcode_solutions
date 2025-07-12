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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2)
        return NULL;

        ListNode* curr = NULL;
        ListNode* head = NULL;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = carry;

            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum %10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);

            if(head == NULL)
            {
                head = newNode;
                curr = head;
            }
            else
            {
                curr->next = newNode;
                curr = curr->next;
            }
        }

        return head;

    }
};