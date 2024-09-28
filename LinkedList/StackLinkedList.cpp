#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


Node* top = nullptr;


void push(int value) {
    Node* newNode = new Node(value);  
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack.\n";
}


void pop() {
    if (top == nullptr) {
        cout << "Stack is empty, nothing to pop.\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << temp->data << " popped from stack.\n";
    delete temp;
}


int peek() {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return -1;  
    }
    return top->data;
}


bool isEmpty() {
    return top == nullptr;
}



int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element is: " << peek() << endl;

    pop();
    pop();
    pop();

    if (isEmpty()) {
        cout << "Stack is empty now.\n";
    }

   
 

    return 0;
}
