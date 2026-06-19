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
    
    //Main Logic of bubble sort
    for(int i=n-1; i>=1; i--){
        bool swapped = false;
        for(int j=0; j<=i-1; j++){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
        if(!swapped)  break;
    }

    //Printing sorted array elements
    for(int i =0; i<n; i++){
        cout<<" "<<arr[i];
    }
    return 0;
}
