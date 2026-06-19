//Problem - 8 --> Linear Search n array.
void search_ele(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i] == x){ cout<<endl<<"Element present in array!";
            return;
        }
    }
    cout<<endl<<"Element not in the array!";
}
