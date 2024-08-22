#include <iostream>
using namespace std;

int main() {
    int rows, columns;

    // Input the dimensions of the matrices
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    int matrix1[10][10], matrix2[10][10], difference[10][10];

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix2[i][j];
        }
    }

    // Subtract the second matrix from the first matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Output the result
    cout << "Difference of the two matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << difference[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
