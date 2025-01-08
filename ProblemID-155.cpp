class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class MinStack 
{
public:
    Node* t;
    MinStack() 
    {
        t = NULL;
    }
    
    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = t;
        t = newNode;
    }
    
    void pop() 
    {
        if(t == NULL)
        return;
        Node* temp = t;
        t = t->next;
        delete temp;
    }
    
    int top()
    {
        return t->data;
    }
    
    int getMin()
    {
        Node* temp = t;
        int min = INT_MAX;
        while(temp != NULL)
        {
            if(temp->data < min)
            min = temp->data;
            temp = temp->next;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */