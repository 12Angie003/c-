#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
};

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
              cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear++;
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int temp = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return temp;
    }
};

int main() {
    // Test Stack
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Popped: " << s.pop() << endl;
 // Test Queue
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
And here's an implementation using linked lists:

cpp
Copy code
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }
  void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty())
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        if (front == rear)
            front = rear = nullptr;
        else
            front = front->next;
        delete temp;
        return dequeuedValue;
    }
};

int main() {
    // Test Stack
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Popped: " << s.pop() << endl;
      // Test Queue
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}