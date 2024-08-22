#include <iostream>
#include <cstring>  // For strlen and strcpy
using namespace std;

// Function to reverse a string using a dynamic stack array
void reverseString(const char input[], char output[]) {
    int length = strlen(input);  // Calculate the length of the input string

    // Dynamically allocate memory for the stack array
    char* stack = new char[length];

    // Push characters onto the stack
    int top = 0;  // Stack top index
    for (int i = 0; i < length; i++) {
        stack[top++] = input[i];
    }

    // Pop characters from the stack and form the reversed string
    int index = 0;
    while (top > 0) {
        output[index++] = stack[--top];
    }
    output[index] = '\0';  // Null-terminate the output string

    // Free the dynamically allocated memory
    delete[] stack;
}

int main() {
    char str[100];
    char reversed[100];

    // Input the string
    cout << "Enter a string: ";
    cin.getline(str, 100); // Reads a line of text from standard input

    // Reverse the string
    reverseString(str, reversed);

    // Output the reversed string
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
