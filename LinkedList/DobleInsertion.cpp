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

void insertAfter(int num, int val) {
    Node* ptr = start;
    while (ptr != nullptr && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == nullptr) {
        cout << val << " not found in the list." << endl;
        return;
    }
    Node* new_node = new Node(num);
    new_node->next = ptr->next;
    new_node->prev = ptr;
    if (ptr->next != nullptr) {
        ptr->next->prev = new_node;
    }
    ptr->next = new_node;
}

void insertBefore(int num, int val) {
    if (start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (start->data == val) {
        insertBeg(num);
        return;
    }

    Node* ptr = start;
    while (ptr != nullptr && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == nullptr) {
        cout << val << " not found in the list." << endl;
        return;
    }

    Node* new_node = new Node(num);
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
}

int main() {
    int choice, num, val;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value\n";
        cout << "4. Insert before a value\n";
        cout << "5. Traverse the Doubly Linked List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> num;
                insertBeg(num);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> num;
                insertEnd(num);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> num;
                cout << "Enter value after which to insert: ";
                cin >> val;
                insertAfter(num, val);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> num;
                cout << "Enter value before which to insert: ";
                cin >> val;
                insertBefore(num, val);
                break;
            case 5:
                traverse();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
