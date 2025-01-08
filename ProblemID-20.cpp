class Node
{
    public:
    char data;
    Node* next;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
    public:
    Node* top;
    Solution()
    {
        top = NULL;
    }

    void push(char val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if(top==NULL)
        {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    
    bool isValid(string s)
    {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='{' || s[i]=='['|| s[i]=='(')
            {
                push(s[i]);
            }
            else
            {
                if(top==NULL)
                {
                    return false;
                }
                if((s[i]=='}' && top->data=='{') || (s[i]==']' && top->data=='[') || (s[i]==')' && top->data=='('))
                pop();
                else
                return false;
            }
        }
        return top==NULL;
    }
};