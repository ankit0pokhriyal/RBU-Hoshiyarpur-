#include<iostream>

using  namespace std;
struct Node {
    int data;
    Node * next;
    Node (int num): data(num), next(nullptr){};
};
Node * start = nullptr;
void traversal(){
    if (start == nullptr){
        cout<< "List empty"<< endl;
    }
    else {
        Node *ptr = start;
        while(ptr->next !=start)
        {
            cout << ptr->data << "-->";
            ptr = ptr->next;
        }
        cout<<ptr->data<< endl;
    }
}

void insertBeg(int num)
{
    Node *new_node = new Node(num);
    if (start == nullptr)
    {
        start = new_node;
        new_node->next = start;
    }
    else {
        Node *ptr = start;
        while(ptr->next != start)
        {
            ptr = ptr->next;
        }
        new_node ->next = start;
        ptr->next = new_node;
        start = new_node;

    }
}
void insertEnd(int num)
{
    Node *new_node = new Node(num);
    if (start == nullptr)
    {
        start = new_node;
        new_node->next = start;
    }
    else {
       
        Node *ptr = start;
        while(ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next =new_node;
        new_node->next = start;
    }

}
void insertAfter(int num, int val)
{
    if (start == nullptr){
        cout<< "List empty"<<endl;
        return;
    }
    Node *new_node = new Node(num);

    Node *ptr = start;
  
    while(ptr->next != start && ptr->data!= val )
        {
            ptr = ptr->next;
        }
    if (ptr->data == val){
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    else{
        cout << "Value Not exist";
    }
}
void insertBefore(int num, int val)
{
    if (start == nullptr){
        cout<< "List empty"<<endl;
        return;
    }
    if (start->data == val){
        insertBeg(num);
        return;
    }
    Node *new_node = new Node(num);
    Node * preptr = nullptr;
    Node *ptr = start;
    while(ptr->next != start && ptr->data!= val )
        {
    preptr =ptr;
    ptr =ptr->next;
        }
    if (ptr->data == val){
        new_node->next=ptr->next;
        preptr->next=new_node;
    }
    else {
        cout << "Value not Found";
    }
}
void deleteBeg()
{
    if (start == nullptr){
        cout<< "List empty"<<endl;
    }
    else if (start->next == start){
        delete start;
        start = nullptr;
    }
    else {
        Node* ptr = start;
        while(ptr->next != start)
        {
            ptr = ptr->next;
        }
        Node *temp = start;
        start=start->next;
        ptr->next=start;
        delete temp;

    } 
}
void deleteEnd()
{
    if (start == nullptr){
        cout<< "List empty"<<endl;
    }
    else if (start->next == start){
        delete start;
        start = nullptr;
    }
    else {
        Node *preptr = nullptr;
        Node* ptr = start;
        while(ptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
       preptr->next = ptr->next;
        delete ptr;

    }    
}
void deleteAtPos(int val)
{
    if (start == nullptr){
        cout<< "List empty"<<endl;
    }
    else if (start->next == start){
        delete start;
        start = nullptr;
    }
    else {
        Node *preptr = nullptr;
        Node* ptr = start;
        while(ptr->next != start && ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr->data == val)
        {
            preptr->next = ptr->next;
            delete ptr;
        }
        else {
            cout<< "List Empty"<<endl;
        }

    }    
}
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertBeg(5);
    traversal(); 

    insertAfter(15, 10);
    traversal(); 

    insertBefore(25, 30);
    traversal(); 
    deleteBeg();   
    traversal();   
    
    deleteEnd();   
    traversal();   
    
    deleteAtPos(15);   
    traversal();   
    
    deleteAtPos(50);   
    traversal();   

    return 0;
}