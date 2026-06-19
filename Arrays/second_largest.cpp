#include <bits/stdc++.h>
using namespace std;

// Problem - 2: Find second largest element in an array.

// Aproach - 1 (brute solution) -- takes n+logn TC

// int arr_Slargest(int arr[], int n)
// {
//     sort(arr, arr + n);
//     int max = arr[n - 1];

//     for (int i = n - 2; i > 0; i--)
//     {
//         if (arr[i] != max)  
//             return arr[i];
//     }
//     return -1;
// }

//Approach - 2 (better solution) --> takes O(n+n) TC
// int arr_Slargest(int arr[], int n){
//     int largest = -1;
//     int second_largest = -1;

//     for(int i=0; i<n; i++){
//         if(arr[i]>largest){
//             largest = arr[i];
//         }
//     }
//     for(int i=0; i<n; i++){
//         if(arr[i]>second_largest && arr[i] != largest){
//            second_largest = arr[i];
//         }
//     }
//     return second_largest;
// }

//Approach - 3 -- Optimal solution that takes O(n) TC.
 int arr_Slargest(int arr[], int n){
     int largest = arr[0];
     int Slargest = -1;

     for(int i=0; i<n; i++){
         if(arr[i]>largest){
              Slargest = largest;
              largest = arr[i];
         }

         else if(arr[i]<largest && arr[i]>Slargest){
             Slargest = arr[i];
         }
     }

     return Slargest;
 }

int main()
{
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
  
    //Problem - 3
     bool a = arr_s(arr, n);
     if(a==true){
         cout<<endl<<"Array is sorted";
     }
     else {
         cout<<endl<<"Array is not sorted";
     }


    return 0;
}
