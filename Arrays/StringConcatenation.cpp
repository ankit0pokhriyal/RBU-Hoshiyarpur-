#include <iostream>
using namespace std;


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

// Function to concatenate two C-style strings using array indexing
void concatenateStrings(char destination[], const char source[]) {
    int destLen = stringLength(destination);  // Length of the destination string
    int i = 0;

    // Append each character from source to the end of destination
    while (source[i] != '\0') {
        destination[destLen + i] = source[i];
        i++;
    }
    destination[destLen + i] = '\0';  // Null-terminate the resulting string
}

int main() {
    char str1[100] = "Hello, ";
    char str2[] = "World!";

    // Concatenate str2 to str1
    concatenateStrings(str1, str2);
    
    // Output the concatenated string
    cout << "Concatenated string: " << str1 << endl;

    return 0;
}

// Function to concatenate two C-style strings using array indexing
void concatenateStrings(char destination[], const char source[]) {
    int destLen = stringLength(destination);  // Length of the destination string
    int i = 0;

    // Append each character from source to the end of destination
    while (source[i] != '\0') {
        destination[destLen + i] = source[i];
        i++;
    }
    destination[destLen + i] = '\0';  // Null-terminate the resulting string
}

int main() {
    char str1[100] = "Hello, ";
    char str2[] = "World!";

    // Concatenate str2 to str1
    concatenateStrings(str1, str2);
    
    // Output the concatenated string
    cout << "Concatenated string: " << str1 << endl;

    return 0;
}
