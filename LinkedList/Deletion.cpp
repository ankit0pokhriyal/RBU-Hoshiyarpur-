#include<iostream>
using namespace std;

struct Node{
  int data;
  Node * next;
  Node(int val): data(val), next(nullptr){};
};                                             
Node *start = nullptr;

void traverse(){
  Node *ptr = start;
  if (ptr == nullptr)
  {
    cout << "List is empty"<< endl;
    return;
  }
  while(ptr != nullptr){
    cout << ptr->data<< "->";
    ptr = ptr->next;
  }
  cout << endl;
}

void insertBeg(int num){
  Node *new_node = new Node(num);
  new_node-> next = start;
  start = new_node;
}

void insertEnd(int num){
  Node *new_node = new Node(num);
  if (start == nullptr){
    start = new_node;
  }
  else{
    Node *ptr = start;
    while(ptr->next != nullptr){
      ptr = ptr->next;
    }
    ptr->next = new_node;
  }
}

void insertAfter(int num, int val) {
  Node *ptr = start;
  while(ptr != nullptr && ptr->data != val) {
    ptr = ptr->next;
  }
  if (ptr == nullptr){
    cout << val << " Not Exist" << endl;
    return;
  }
  Node *new_node = new Node(num);
  new_node->next = ptr->next;
  ptr->next = new_node;
}

void insertBefore(int num, int val){
  Node *new_node = new Node(num);
  if (start == nullptr){
    cout << "List is empty, cannot insert before";
    return;
  }
  if(start->data == val){
    new_node -> next  = start;
    start = new_node;
    return;
  }

  Node *ptr = start;
  Node *preptr = nullptr;
  while(ptr != nullptr && ptr->data != val){
    preptr = ptr;
    ptr = ptr->next;
  }
  new_node->next  = ptr;
  preptr->next = new_node;
}

// Deleting from the beginning
void deleteBeg() {
  if (start == nullptr) {
    cout << "List is empty, cannot delete" << endl;
    return;
  }
  Node *ptr = start;
  start = start->next;
  delete ptr;
  cout << "Node deleted from beginning" << endl;
}

// Deleting from the end
void deleteEnd() {
  if (start == nullptr) {
    cout << "List is empty, cannot delete" << endl;
    return;
  }
  Node *ptr = start;
  Node *preptr = nullptr;

  if (start->next == nullptr) {
    delete start;
    start = nullptr;
  } else {
    while (ptr->next != nullptr) {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = nullptr;
    delete ptr;
  }
  cout << "Node deleted from end" << endl;
}

// Deleting a specific node by value
void deleteNode(int val) {
  if (start == nullptr) {
    cout << "List is empty, cannot delete" << endl;
    return;
  }
  Node *ptr = start;
  Node *preptr = nullptr;

  if (start->data == val) {
    start = start->next;
    delete ptr;
    cout << "Node with value " << val << " deleted" << endl;
    return;
  }

  while (ptr != nullptr && ptr->data != val) {
    preptr = ptr;
    ptr = ptr->next;
  }

  if (ptr == nullptr) {
    cout << "Node with value " << val << " not found" << endl;
    return;
  }
  
  preptr->next = ptr->next;
  delete ptr;
  cout << "Node with value " << val << " deleted" << endl;
}

// Main function to demonstrate the usage
int main() {
  int choice, num, val;

  while (true) {
    cout << "\nMenu:\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert after a value\n";
    cout << "4. Insert before a value\n";
    cout << "5. Traverse\n";
    cout << "6. Delete from beginning\n";
    cout << "7. Delete from end\n";
    cout << "8. Delete specific value\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        insertBeg(2);
        insertBeg(4);
        insertBeg(5);
        break;
      case 2:
        insertEnd(6);
        break;
      case 3:
        cout << "Enter value to insert after: ";
        cin >> val;
        insertAfter(55, val);
        break;
      case 4:
        cout << "Enter value to insert before: ";
        cin >> val;
        insertBefore(46, val);
        break;
      case 5:
        traverse();
        break;
      case 6:
        deleteBeg();
        break;
      case 7:
        deleteEnd();
        break;
      case 8:
        cout << "Enter value to delete: ";
        cin >> val;
        deleteNode(val);
        break;
      case 9:
        cout << "Exiting the program." << endl;
        return 0;
      default:
        cout << "Invalid choice, please try again." << endl;
    }
  }
}