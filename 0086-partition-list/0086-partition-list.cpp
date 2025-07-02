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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* lhead = new ListNode(0);
        ListNode* rhead = new ListNode(0);

        ListNode* l = lhead;
        ListNode* r = rhead;

        ListNode* temp = head;

        while(temp != NULL)
        {
            if(temp->val < x)
            {
                l->next = temp;
                l = l->next;
            }
            else
            {
                r->next = temp;
                r = r->next;
            }

            temp = temp->next;
        }
        l->next = rhead->next;
        r->next = NULL;

        return lhead->next;
    }
};