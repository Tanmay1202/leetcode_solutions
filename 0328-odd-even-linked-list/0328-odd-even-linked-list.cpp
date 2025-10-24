class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddTail = head;
        ListNode* evenTail = head->next;

        ListNode* temp = head->next->next;
        bool isOdd = true;

        while(temp != nullptr)
        {
            if(isOdd)
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }

            isOdd = !isOdd;
            temp = temp->next;
        }

        oddTail->next = evenHead;
        evenTail->next = nullptr;

        return oddHead;
    }
};
