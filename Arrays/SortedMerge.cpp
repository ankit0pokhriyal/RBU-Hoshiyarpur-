#include <iostream>
using namespace std;

int main() {
    int i,j,z{0},i2{0}, j2{0},n1, n2, n3, arr1[20], arr2[20], arr[40], index;

    cout << "Enter the No. of elements for sorted arr1: ";
    cin >> n1;
    // Enter the elements of array for size n1
    // CODE HERE


    cout << "Enter the No. of elements for sorted arr2: ";
    cin >> n2;

    // Enter the elements of an array for size  n2
    // CODE HERE


    // ADD SIZE {HINT : n3 will be n1+n2}
    // CODE HERE
    

    // Till i2 < n1 and j2 <n2
    // CODE HERE
   
        // If arr1[i2] < arr2[j2]  fill arr[z] with arr1[i2] elements
        // Remember to increase respective Indexes.
        // CODE HERE
       
        // IF arr1[i2]>= arr2[j2] fill arr[z] with arr2[j2] elements
        // Remember to Increase Respective Indexes.
        // CODE HERE
      
    

   // IF any one of the Two merging array get completely filled in Merged Array
   // Insert the elements of another array into Merged Array.
   // For this just check
   // till j2 <n2 Enter elements of array2 into merged array.
   // CODE HERE
  
   // Similliarly till i2 < n1
   // Enter elements of array1 into merged array.
   // CODE HERE
 
    cout <<"The Merged Array is:\n";
    // CODE HERE
    
    for (index = 0 ; index < n3;index++)
    {
        cout<<arr[index];
    }
    return 0;
}