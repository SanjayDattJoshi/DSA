//Problem - 5 --> Left rotate the array by 1.
//Approach - 1 --> take another array and put a[i] in temp[i-1]


//Approach - 2 
void left_rotate(int arr[], int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
