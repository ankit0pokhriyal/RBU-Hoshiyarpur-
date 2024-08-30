#include <iostream>
using namespace std;


int stringLength(const char str[]) {
   // Function to find String Length
   // CODE HERE
   
}

void concatenateStrings(char string1[], const char string2[]) {
    int string1Length = stringLength(string1); 
    int i = 0;

    // Append each character from source to the end of destination
    // CODE HERE 
    // ADD NULL Ccharacter to string.
    // CODE HERE
}

int main() {
    char str1[100] = "Ankit";
    char str2[] = "Pokhriyal";

    // Concatenate str2 to str1
    concatenateStrings(str1, str2);
    
    // Output the concatenated string
    cout << "Concatenated string: " << str1 << endl;

    return 0;
}