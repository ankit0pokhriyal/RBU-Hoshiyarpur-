#include <iostream>
#include <stack>
#include <string>
# include <cmath>
using namespace std;

// Function to perform an operation and return the result
int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);  
        default: return 0;
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char ch : postfix) {
        // If the character is an operand (assuming it's a digit here)
        if (isdigit(ch)) {
            s.push(ch - '0');  
        } 
        // If the character is an operator
        else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result = performOperation(operand1, operand2, ch);
            s.push(result);
        }
    }

    // The result will be the only value left in the stack
    return s.top();
}

int main() {
    string postfix ="123*+4-";


    int result = evaluatePostfix(postfix);
    cout << "Result of the postfix evaluation: " << result << endl;

    return 0;
}
