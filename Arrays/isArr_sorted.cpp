#include <bits/stdc++.h>
using namespace std;

//Problem - 3 --> Check if the array is sorted or not.

bool arr_s(int arr[], int n){
  
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])  return false;
        else return true;
    }
}
int main()
{
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
