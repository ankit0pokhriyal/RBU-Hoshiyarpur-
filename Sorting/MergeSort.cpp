#include <iostream>
using namespace std;
void Merge(int arr[], int beg, int mid, int end){
    int i = beg, j = mid+1, index = beg, temp[end-beg+1], k;
    while((i<=mid) && (j <=end))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i >mid)
    {
        while(j<=end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else{
        while(i<=mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for (int k = beg; k <= end; k++) {
        arr[k] = temp[k];
    }


}
void mergeSort(int arr[], int beg, int end) {
    if (beg<end)  {
        int mid = beg + (end-beg)/ 2;

        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);

        Merge(arr, beg, mid, end);
    }
}

void printArray(int arr[], int n) {
    for (int k=0; k<n; k++)
        cout << arr[k] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {35,65,02,204,456,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< "Unsorted ARRAy: ";
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);

    cout<< "sorted ARRAy: ";
    printArray(arr, n);
    return 0;
}