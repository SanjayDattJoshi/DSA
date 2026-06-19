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
    
    //Main Logic of insertion sort
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j], arr[j-1]);
        }
    }
    //Printing sorted array elements
    for(int i =0; i<n; i++){
        cout<<" "<<arr[i];
    }
    return 0;
}
