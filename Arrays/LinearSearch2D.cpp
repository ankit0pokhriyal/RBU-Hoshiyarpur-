#include <iostream>
using namespace std;

int main() {
    int rows, columns, target;

    // Input the dimensions of the 2D array
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    int array[5][5];

    // Input elements of the 2D array
    cout << "Enter elements of the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << " arr(" << i+1 << ", " << j+1 << "): ";
            cin >> array[i][j];
        }
    }

    // Input the target element to search for
    cout << "Enter the element to search for: ";
    cin >> target;

    // Linear search in the 2D array
    bool found = false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (array[i][j] == target) {
                cout << "Element found at position (" << i + 1 << ", " << j + 1 << ")." << endl;
                found = true;
                break; // If you want to stop after finding the first occurrence
            }
        }
        if (found) break; // Break outer loop if element is found
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
