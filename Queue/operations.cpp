#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the queue

class Queue {
private:
    int front, rear, size;
    int que[MAX];

public:
    Queue() :front(0), rear(-1), size(0){}

    // Add an element to the end of the queue
    void enqueue(int val) {
    // Check overflow
    // If Not overflow 
    // Insert element at rear
    // increase rear and size 
    // CODE HERE
    }

    // Remove an element from the front of the queue
    void dequeue() {
        // Check Underflow
       
        // Shift all elements to the left
        // Decrease size and rear also
    }

    // Get the front element of the queue
    int getFront() {
        // Check Whether queue is empty or not
        // If not get front element
        // CODE HERE
    }

    // Check if the queue is empty
    bool isEmpty() {
    // Chcek whether queue is empty 
    // CODE HERE
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