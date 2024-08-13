#include<iostream>
using namespace std;
int main()
{
    int i, j, num, n;
    int arr[40] = {2,4,7,9,10,22,24};  // 7 elements
    cout << "Elements of an array are:"<<endl<<"{2,4,7,9,10,22,24}"<< endl;
    cout <<"Enter the number you want to Delete: "<< endl;
    cin >> num;
    n = 7;  

    // Define bool as false 
    bool found = false;

    // Use iterative loop to find the required element
    for ( i = 0; i < n; i++ )
    {   
        // IF element is found 
        // CODE HERE

        // change the  found = true
        // CODE HERE

        // Delete the element  as done before
        // CODE HERE

        // Remember to use break statement
        // CODE HERE
    
        
    }
    // if found  !=  true
    if (!found)
    {
        cout << "Number not found in the array." << endl;
    }
    else{
    cout<< "The new array is: "<< endl;
    for (i=0; i<n; i++)
    {
        cout<< arr[i]<< endl;
    }
    }
    return 0;
}