// Lab 4 - SECJ2013 - 24251 (Lab4.cpp)
// Group Members:
// 1. Chua Jia Lin A23CS0069
// 2. Cheryl Cheong Kah Voon A23CS0060

#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Node class to implement circular linked-list type queue
class Node {
    private:
        char item;
        Node *next;

    public:
        Node(char c) { 
            item = c; 
            next = NULL;
        }

        void setNext(Node *n) { next = n; }
        Node *getNext() { return next; }
        char getItem() { return item; }

        ~Node() { cout << "Delete node-item " << item << "\n"; }
};

// Queue class header (array)
class Queue {
private:
    Node *front, *rear;
    char items[size];
    int MAX_QUEUE = size; 
    int count;

public:
    void createQueue();
    void destroyQueue();
    void enQueue(char);
    char deQueue();
    bool isEmpty();
    bool isFull();
    char getFront();
    char getRear();
};

// Queue class implementation (array)
void Queue::createQueue() {
    front = NULL;
    rear = NULL;
    count = 0;
}

void Queue::enQueue(char c) {
    cout << "Try to enqueue item " << c << " into the queue\n";
    
    if(isFull()){
        cout << "Can't enqueue item " << c << ", queue is full!\n";
        return;
    }

    Node *newNode = new Node(c);
    if(isEmpty()){
        front = rear = newNode;
        rear->setNext(front);

    }else {
        newNode->setNext(front);
        rear->setNext(newNode);
        rear = newNode;
    }

    count++;
    
}

char Queue::deQueue() {
    if (isEmpty()) {
        cout << "Can't dequeue item, queue is empty!\n";
        return ' ';
    }

    char c = front->getItem();
    if(front == rear){
        //delete front;
        front = NULL;
        rear = NULL;
    }
    else{
        Node *currNode = front;
        front = front->getNext();
        rear->setNext(front);
        //delete currNode;
    }

    count--;
    return c;
    
}

bool Queue::isFull() {
    if (count >= size)
        return true;
    else 
       return false;
}

bool Queue::isEmpty() {
    return front == NULL;
}

char Queue::getFront() {
    if (!isEmpty()) {
        return front->getItem();
    } else {
        cout << "Can't get front item, queue is empty!\n";
        return ' ';
    }
}

char Queue::getRear() {
    if (!isEmpty()) {
        return rear->getItem();
    } else {
        cout << "Can't get rear item, queue is empty!\n";
        return ' ';
    }
}

// Main function section
int main() {
    Queue myQueue;

    myQueue.createQueue();

    myQueue.enQueue('A');
    myQueue.enQueue('B');
    myQueue.enQueue('C');
    myQueue.enQueue('D');
    myQueue.enQueue('E');
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";
    
    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    cout << "\n";
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    system("pause");
    return 0;
}
