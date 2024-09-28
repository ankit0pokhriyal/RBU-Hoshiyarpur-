#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* start = nullptr;

void traverse() {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* ptr = start;
    while (ptr != nullptr) {
        cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void insertBeg(int num) {
    Node* new_node = new Node(num);
    if (start == nullptr) {
        start = new_node;
    } else {
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
}

void insertEnd(int num) {
    Node* new_node = new Node(num);
    if (start == nullptr) {
        start = new_node;
    } else {
        Node* ptr = start;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

void deleteBeg() {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = start;
    if (start->next == nullptr) { 
        start = nullptr;
    } else {
        start = start->next;
        start->prev = nullptr;
    }
    delete temp;
}

void deleteEnd() {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* ptr = start;
    if (start->next == nullptr) { 
        start = nullptr;
        delete ptr;
    } else {
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->prev->next = nullptr;
        delete ptr;
    }
}

void deleteAtPos(int val) {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* ptr = start;
    while (ptr != nullptr && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == nullptr) {
        cout << "Value " << val << " not found in the list." << endl;
        return;
    }
 if (ptr == start) {
        start = ptr->next;
        if (start != nullptr) {
            start->prev = nullptr; 
        delete ptr;
    }
 }
    else {
        if (ptr->prev != nullptr) {
            ptr->prev->next = ptr->next;
        }

        if (ptr->next != nullptr) {
            ptr->next->prev = ptr->prev;
        }
        delete ptr;
    }

    
}

int main() {
    insertBeg(10);
    insertBeg(20);
    insertEnd(30);
    insertEnd(40);
    
    cout << "Initial list: ";
    traverse(); 

    deleteBeg();
    cout << "After deleting from beginning: ";
    traverse(); 

    deleteEnd();
    cout << "After deleting from end: ";
    traverse(); 

    deleteAtPos(20);
    cout << "After deleting value 20: ";
    traverse(); 

    deleteAtPos(50);
    cout << "Attempt to delete value 50: ";
    traverse(); 
}