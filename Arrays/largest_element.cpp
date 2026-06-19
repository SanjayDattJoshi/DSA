//this is an Brute solution for the problem find largest element in a array.

#include<bits/stdc++.h>
using namespace std;

int arr_largest(int arr[], int n){  
    sort(arr, arr + n);
    return arr[n-1];
}

int main(){
    // Input array size
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Initializing array with size n
    int arr[n];

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = arr_largest(arr, n);  
    cout << "Largest element: " << largest << endl; 

    return 0;
}
