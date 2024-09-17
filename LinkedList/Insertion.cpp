#include<iostream>
using namespace std;
struct Node{
  int data;
  Node * next;
  Node(int val): data(val), next(nullptr){};
};
Node *start = nullptr;

void traverse(){

}

void insertBeg(int num){
 
}
void insertEnd(int num){

  }


void insertAfter(int num, int val)
{
 
}

void insertBefore(int num, int val){

}
// Main function to demonstrate the usage
int main() {
    int choice;

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


