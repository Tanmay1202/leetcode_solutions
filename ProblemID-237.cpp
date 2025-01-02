class Solution {
public:
    void deleteNode(ListNode* node)
    {
        // ListNode* head = node;
        // while(head->next!=NULL)
        // {
        //     head->val = head->next->val;
        //     if(head->next->next == NULL)
        //     head->next = NULL;
        //     else
        //     head = head->next;
        // }

        ListNode* temp;
        while(node->next)
        {
            temp = node;
            node->val = node->next->val;
            node = node->next;
        }
        temp->next = NULL;
    }
};