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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp->next != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        temp = head;
        int j = 0;
        while(j<(cnt+1)/2)
        {
            temp = temp->next;
            j++;
        }
        return temp;
    }
};