class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(temp->val == val)
            {
                arr.push_back(val);
            }
            temp = temp->next;
        }
        
        for(int i=0; i<arr.size(); i++)
        {
            long long int pos = 1;
            temp = head;
            while(temp != NULL && temp->val!=arr[i])
            {
                pos++;
                temp = temp->next;
            }
            if(pos==1)
            {
                ListNode* t = head;
                head = head->next;
                delete t;
            }
            else
            {
                ListNode* prev = NULL;
                ListNode* curr = head;
                int c = 1;
                while(c<pos)
                {
                    prev = curr;
                    curr = curr->next;
                    c++;
                }
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
            }
        }
        return head;
    }
};