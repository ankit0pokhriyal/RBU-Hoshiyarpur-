#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

  
    Node(int num) : data(num), next(nullptr) {}
};
Node* front = nullptr;
Node* rear = nullptr;


void enqueue(int value) {
    Node* newNode = new Node(value);  

    if (rear == nullptr) {
        front = rear = newNode;
        cout << value << " enqueued to queue.\n";
        return;
    }

    rear->next = newNode;
    rear = newNode;
    cout << value << " enqueued to queue.\n";
}


void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty, nothing to dequeue.\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    cout << temp->data << " dequeued from queue.\n";
    delete temp;
}


int peek() {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return -1;  
    }
    return front->data;
}

bool isEmpty() {
    return front == nullptr;
}





int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Front element is: " << peek() << endl;

    dequeue();
    dequeue();
    dequeue();

    if (isEmpty()) {
        cout << "Queue is empty now.\n";
    }

    return 0;
}
