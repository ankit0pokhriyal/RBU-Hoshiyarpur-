#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int val)
{ 
    // Initialize beg and end;
    // CODE HERE
    
    // till beg <= end run the loop
    // CODE HERE

        // mid = Average of beg and end
        // CODE HERE

        // if array at mid == value  return mid
        // CODE HERE

        // if array at mid > value  change end  =  mid-1
        // CODE HERE

        // if array at mid < value change beg = mid + 1
        // CODE HERE
    
    return -1;

}
int main()
{
    int arr[] = {3,45,6l,67,88,90,96};
    //calculate size of  an array
    // CODE HERE

    int val;
    cout <<"Enter the no. to be search: ";
    cin >>val;

    // call the function in result {HINT : result  = BinarySearch(arr, n, val)}
    // CODE HERE Change th statement below.
    int result;
    if (result != -1)
    {
        cout << "Element found at index :"<< result;

    }
    else 
    cout << "Element not found.";
    return 0;
}