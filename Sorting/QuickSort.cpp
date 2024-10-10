#include <iostream>
using namespace std;

int Partition(int arr[], int beg, int end) {
    int left, right, loc;
    loc = left = beg;
    right = end;

    while (true) {
        
        while (arr[loc] <= arr[right] && loc != right) {
            right--;
        }
        if (loc == right) {
            break;  
        } else if (arr[loc] > arr[right]) {
            swap(arr[loc], arr[right]);
            loc = right; 
        }
\
        while (arr[loc] >= arr[left] && loc != left) {
            left++;
        }
        if (loc == left) {
            break; 
        } else if (arr[loc] < arr[left]) {
            swap(arr[loc], arr[left]);
            loc = left;  
        }
    }

    return loc;  
}

void quickSort(int arr[], int beg, int end) {
    if (beg < end) {
        int loc = Partition(arr, beg, end); 
        quickSort(arr, beg, loc - 1);  
        quickSort(arr, loc + 1, end);  
    }
}

void printArray(int arr[], int n) {
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {35, 65, 2, 204, 456, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
