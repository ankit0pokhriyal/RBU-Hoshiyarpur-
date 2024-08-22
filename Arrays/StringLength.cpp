#include <iostream>
using namespace std;

// Function to calculate the length of a C-style string
int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];

    // Input the string
    cout << "Enter a string: ";
    cin>> str;

    // Calculate the length of the string
    int length = stringLength(str);
    cout << "Length of the string: " << length << endl;

    return 0;
}
