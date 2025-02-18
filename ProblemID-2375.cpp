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

class Solution {
public:
    Node* t;
    Solution()
    {
        t = NULL;
    }
    void push(char val)
    {
        Node* newNode = new Node(val);
        newNode->next = t;
        t = newNode;
    }

    char pop()
    {
        if(t == NULL)
        {
            return -1;
        }
        Node* temp = t;
        char popped = t->data;
        t = t->next;
        delete temp;
        return popped;
    }

    char top()
    {
        if(t == NULL)
        return '0';
        return t->data;
    }


    bool isEmpty()
    {
        return t == NULL;
    }

    string smallestNumber(string pattern)
    {
        int s = pattern.size();
        string str;
        for(int i=0; i<=s; i++)
        {
            push('1' + i);
            if(i == s || pattern[i] == 'I')
            {
                while(!isEmpty())
                {
                    str.push_back(pop());
                }
            }
        }
        return str;
    
    }
};