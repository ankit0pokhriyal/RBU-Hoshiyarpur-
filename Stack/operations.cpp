#include <iostream>
#define MAX 5  // Define the maximum size of the stack
using namespace std;
class Stack {
private:
    int stk[MAX];  
    int top;      

public:
    // Constructor initializing top =-1
    Stack() {top =-1;}  

    // Push Operation
    void push(int val){
        // Check Overflow
        // Else enter the element at top position
        // Increase the size 
        // CODE HERE
    }

    // Pop operation 
    void pop() {
        // Check Underflow
        // else remove the element from top position
        // decrease the size 
        // CODE HERE
    }

    // Peek operation to view the top element 
    // In c++ std top is key word.
    int peek() {
     // Check stack is empty or not 
     // if not empty show the top position 
     // CODE HERE
    }

    // Check if the stack is empty
    bool empty() {
        // return empty condition 
        // CODE HERE
    }

    // Get the current size of the stack
    int size() {
        // return the size of stack
        //CODE HERE
    }
};

int main() {
    Stack S;

    // Push elements onto the stack
    S.push(302);
    S.push(300);
    S.push(33);

    // Display the top element (peek)
    cout << "Top element: " << S.peek() << endl;

    // Pop an element from the stack
    S.pop();
    cout << "Top element after pop: " << S.peek() <<endl;

    // Push another element
    S.push(40);
    cout << "Top element after another push: " << S.peek() << endl;

    // Push more elements to test overflow
    S.push(500);
    S.push(640);  
    S.push(720);  

    // Print the size of the stack
    cout << "Size of the stack: " << S.size() << std::endl;

    // Pop all elements to test underflow
    // until stack is not empty

    while (!S.empty()) {
        S.pop();
    }

    // Try popping from an empty stack to trigger underflow
    S.pop();

    return 0;
}
