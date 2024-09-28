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
  }
  while(ptr != nullptr){
    cout << ptr->data<< "->";
    ptr = ptr->next;
  }
  cout << endl;
}

void insertBeg(int num){
  // Initialize New Node 
  // 
  Node *new_node = new Node(num);
  new_node-> next =start;
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

void insertAfter(int num, int val)
{
  Node *ptr = start;
  while(ptr !=nullptr && ptr->data != val)
  {
    ptr = ptr->next;
  }
  if (ptr == nullptr){
    cout << val<< "Not Exist"<< endl;
    return;
  }
  Node *new_node  = new Node(num);
  new_node->next = ptr->next;
  ptr->next = new_node;
}

void insertBefore(int num, int val){
  Node * new_node = new Node(num);
  if (start == nullptr){
    cout << "List is empty cannot insert before";
    return;
  }
  if(start->data == val){
    new_node -> next  = start;
    start = new_node;
    return;
  }

  Node *ptr = start;
  Node *preptr = nullptr;
  while(ptr != nullptr && ptr->data != val)
  {
    preptr = ptr;
    ptr = ptr->next;
  }
  new_node->next  = ptr;
  preptr->next = new_node;
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
        cout << "5. Traversing in Linked List\n";
        cout << "6. Exit\n";
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

                insertAfter(55, 4);
                break;
            case 4:

                insertBefore(46, 4);
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



