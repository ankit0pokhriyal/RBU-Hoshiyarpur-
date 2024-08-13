#include <iostream>
using namespace std;
int InterpolationSearch(int arr[], int n, int val)
{
    int beg{0}, end{n-1};
    while (beg <= end)
    {  
        // Value of mid
        // CODE HERE(CHange The below value)
        int mid;
        if (arr[mid] == val)
        return mid;
        if (arr[mid]>val)
        {
            end= mid-1;
        }
        else
        {
            beg = mid+1;
        }

    }
    return -1;

}
int main()
{
    int arr[] = {3,45,6l,67,88,90,96};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val;
    cout <<"Enter the no. to be search: ";
    cin >>val;
    int result = InterpolationSearch(arr,n,val);
    if (result != -1)
    {
        cout << "Element found at index :"<< result;

    }
    else 
    cout << "Element not found.";
    return 0;
}