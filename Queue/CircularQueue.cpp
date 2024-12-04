#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the queue

class Queue {
private:
    int front, rear, size;
    int que[MAX];

public:
    Queue() : front(0), rear(-1), size(0) {}

    // Add an element to the end of the queue
    void enqueue(int val) {
        // Check overflow
        if (size >= MAX) {
            cout << "Overflow" << endl;
            return;
        }
        // Move rear to the next position in a circular manner
        rear = (rear + 1) % MAX;
        que[rear] = val;
        size++;
    }

    // Remove an element from the front of the queue
    void dequeue() {
        // Check underflow
        if (size <= 0) {
            cout << "Underflow" << endl;
            return;
        }
        // Move front to the next position in a circular manner
        front = (front + 1) % MAX;
        size--;
    }

    // Get the front element of the queue
    int getFront() {
        // Check whether the queue is empty
        if (size <= 0) {
            cout << "Queue is empty" << endl;
            return -1;  // Return a sentinel value
        }
        return que[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << " is at the front of the queue" << endl;

    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << q.getFront() << " is at the front of the queue" << endl;
    }

    return 0;
}
