class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class MyCircularQueue {
public:
    Node* front;
    Node* rear;
    int cap;
    int count;

    MyCircularQueue(int k) {
        front = nullptr;
        rear = nullptr;
        cap = k;
        count = 0;
    }

    bool enQueue(int value) {
        if (count == cap) return false;

        Node* temp = new Node(value);

        if (count == 0) {
            front = rear = temp;
            rear->next = front;
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }

        count++;
        return true;
    }

    bool deQueue() {
        if (count == 0) return false;

        if (count == 1) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        count--;
        return true;
    }

    int Front() {
        if (count == 0) return -1;
        return front->data;
    }

    int Rear() {
        if (count == 0) return -1;
        return rear->data;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == cap;
    }
};
