#include <iostream>
using namespace std;

int main() {
    int rows1, columns1, rows2, columns2;

    // Input the dimensions of the first matrix
    cout << "Enter the number of rows"<<endl;
    cin >> rows1;
    cout << "REnter the number of Columns"<< endl;
    cin >> columns1;

    // Input the dimensions of the second matrix
    cout << "Enter the number of rows"<<endl;
    cin >> rows2;
    cout << "REnter the number of Columns"<< endl;
    cin >> columns2;

    // Ensure the matrices can be multiplied
    if (columns1 != rows2) {
        cout << "Matrix multiplication is not possible." << endl;
        return 1;
    }

    int matrix1[5][5], matrix2[5][5], product[25][25];

    // Initialize the product matrix to 0
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            product[i][j] = 0;
        }
    }

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < columns2; ++j){
            cin >> matrix2[i][j];
        }
    }

    // Multiply the matrices
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            for (int k = 0; k < columns1; ++k) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Output the product matrix
    cout << "Product of the two matrices:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
