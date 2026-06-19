#include<bits/stdc++.h>
using namespace std;
int main(){
    //Input array size
    int n;
    cout<<"Enter size of array:";
    cin>>n;

    //Initializing array with size n
    int arr[n];
   
    //Input array elements
    cout<<endl<<"Enter array elements:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    //Main Logic of selection sort
    for(int i=0; i<n-2; i++){
        int min = i;
        for(int j=i; j<n-1; j++){
              if(arr[j]<arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }

    //Printing sorted array elements
    for(int i =0; i<n; i++){
        cout<<" "<<arr[i];
    }
    return 0;
}